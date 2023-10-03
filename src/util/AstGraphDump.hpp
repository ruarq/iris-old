#ifndef IRIS_UTIL_AST_GRAPH_DUMP_HPP
#define IRIS_UTIL_AST_GRAPH_DUMP_HPP

#include <stack>

#include <fmt/format.h>

#include "ast/ExprVisitor.hpp"
#include "ast/ast.hpp"
#include "common.hpp"

namespace iris::util {
	struct AstGraphDump : public ast::ExprVisitor {
	public:
		IRIS_CONSTRUCTOR AstGraphDump();

	public:
		auto dump(ast::Expr &expr) -> void;

	private:
		auto visit(ast::BinaryExpr &binary_expr) -> void override;
		auto visit(ast::UnaryExpr &unary_expr) -> void override;
		auto visit(ast::GroupingExpr &grouping_expr) -> void override;
		auto visit(ast::ValueExpr &value_expr) -> void override;

		auto push_id() -> usz;
		auto pop_id() -> usz;

		auto add_node(usz id, std::string_view label) -> void;
		auto connect_nodes(usz from_id, const std::vector<usz> &to_ids) -> void;

	private:
		std::stack<usz> _id_stack;
		usz _current_id;
	};
}

#endif
