#ifndef IRIS_AST_GROUPING_EXPR_HPP
#define IRIS_AST_GROUPING_EXPR_HPP

#include "AcceptExprVisitor.hpp"
#include "Expr.hpp"
#include "common.hpp"

namespace iris::ast {
	struct GroupingExpr : public AcceptExprVisitor<GroupingExpr> {
	public:
		IRIS_CONSTRUCTOR GroupingExpr(std::unique_ptr<Expr> &&expr);

	public:
		std::unique_ptr<Expr> expr;
	};
}

#endif
