#ifndef IRIS_AST_VALUE_EXPR_HPP
#define IRIS_AST_VALUE_EXPR_HPP

#include "Expr.hpp"
#include "common.hpp"

namespace iris::ast {
	struct ValueExpr : public Expr {
	public:
		IRIS_CONSTRUCTOR ValueExpr(int value);

	public:
		auto eval() -> int override {
			return value;
		}

	public:
		int value;
	};
}

#endif
