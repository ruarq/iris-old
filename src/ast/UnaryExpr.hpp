#ifndef IRIS_AST_UNARY_EXPR_HPP
#define IRIS_AST_UNARY_EXPR_HPP

#include "Expr.hpp"
#include "common.hpp"

namespace iris::ast {
	struct UnaryExpr : public Expr {
	public:
		enum class Op {
			Negate,
		};

	public:
		IRIS_CONSTRUCTOR UnaryExpr(Op op, std::unique_ptr<Expr> &&expr);

	public:
		auto eval() -> int override {
			switch (op) {
				case Op::Negate: return -expr->eval();
			}
		}

	public:
		Op op;
		std::unique_ptr<Expr> expr;
	};
}

#endif
