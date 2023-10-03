#ifndef IRIS_AST_UNARY_EXPR_HPP
#define IRIS_AST_UNARY_EXPR_HPP

#include "AcceptExprVisitor.hpp"
#include "Expr.hpp"
#include "common.hpp"

namespace iris::ast {
	struct UnaryExpr : public AcceptExprVisitor<UnaryExpr> {
	public:
		enum class Op {
			Negate,
		};

	public:
		IRIS_CONSTRUCTOR UnaryExpr(Op op, std::unique_ptr<Expr> &&expr);

	public:
		Op op;
		std::unique_ptr<Expr> expr;
	};
}

#endif
