#ifndef IRIS_AST_VALUE_EXPR_HPP
#define IRIS_AST_VALUE_EXPR_HPP

#include "AcceptExprVisitor.hpp"
#include "Expr.hpp"
#include "common.hpp"

namespace iris::ast {
	struct ValueExpr : public AcceptExprVisitor<ValueExpr> {
	public:
		IRIS_CONSTRUCTOR ValueExpr(int value);

	public:
		int value;
	};
}

#endif
