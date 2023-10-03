#ifndef IRIS_AST_GROUPING_EXPR_HPP
#define IRIS_AST_GROUPING_EXPR_HPP

#include "Expr.hpp"
#include "common.hpp"

namespace iris::ast {
	struct GroupingExpr : public Expr {
	public:
		IRIS_CONSTRUCTOR GroupingExpr(std::unique_ptr<Expr> &&expr);

	public:
		auto eval() -> int override {
			return expr->eval();
		}

	public:
		std::unique_ptr<Expr> expr;
	};
}

#endif
