#include <stack>

#include <fmt/format.h>

#include "ast/ExprVisitor.hpp"
#include "ast/ast.hpp"
#include "common.hpp"
#include "core/Source.hpp"
#include "core/SymbolMap.hpp"
#include "lexer/DefaultLexerImpl.hpp"
#include "lexer/Lexer.hpp"
#include "parser/Parser.hpp"

struct ExprEvaluator : public iris::ast::ExprVisitor {
public:
	IRIS_NODISCARD auto get_result() const -> int {
		return _stack.top();
	}

	auto visit(iris::ast::BinaryExpr &binary_expr) -> void override {
		binary_expr.left->accept(*this);
		binary_expr.right->accept(*this);

		auto rhs = _stack.top();
		_stack.pop();

		auto lhs = _stack.top();
		_stack.pop();

		int result;

		switch (binary_expr.op) {
			case iris::ast::BinaryExpr::Op::Add: result = lhs + rhs; break;
			case iris::ast::BinaryExpr::Op::Sub: result = lhs - rhs; break;
			case iris::ast::BinaryExpr::Op::Mul: result = lhs * rhs; break;
			case iris::ast::BinaryExpr::Op::Div: result = lhs / rhs; break;
			case iris::ast::BinaryExpr::Op::Mod: result = lhs % rhs; break;
		}

		_stack.push(result);
	}

	auto visit(iris::ast::UnaryExpr &unary_expr) -> void override {
		unary_expr.expr->accept(*this);
		auto value = _stack.top();
		_stack.pop();
		_stack.push(-value);
	}

	auto visit(iris::ast::GroupingExpr &grouping_expr) -> void override {
		grouping_expr.expr->accept(*this);
	}

	auto visit(iris::ast::ValueExpr &value_expr) -> void override {
		_stack.push(value_expr.value);
	}

private:
	std::stack<int> _stack;
};

auto main(int argc, char **argv) -> int {
	using namespace iris::ast;

	if (argc != 2) {
		fmt::print("Usage: iris <expr>\n");
		return 1;
	}

	iris::core::Source source{ "<internal>", std::string{ argv[1] } };

	iris::core::SymbolMap symbols;
	iris::lexer::DefaultLexerImpl lexer_impl{ source, symbols };
	iris::lexer::Lexer lexer{ lexer_impl };
	iris::parser::Parser parser{ lexer, symbols };

	ExprEvaluator eval;

	auto expr = parser.parse_expr();
	expr->accept(eval);

	fmt::print("Result: {}\n", eval.get_result());

	return 0;
}
