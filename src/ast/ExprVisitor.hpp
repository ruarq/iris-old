#ifndef IRIS_AST_EXPR_VISITOR_HPP
#define IRIS_AST_EXPR_VISITOR_HPP

#include "common.hpp"

namespace iris::ast {
	struct BinaryExpr;
	struct GroupingExpr;
	struct UnaryExpr;
	struct ValueExpr;

	struct ExprVisitor {
	public:
		virtual ~ExprVisitor() = default;

	public:
		virtual auto visit(BinaryExpr &binary_expr) -> void = 0;
		virtual auto visit(UnaryExpr &unary_expr) -> void = 0;
		virtual auto visit(GroupingExpr &grouping_expr) -> void = 0;
		virtual auto visit(ValueExpr &value_expr) -> void = 0;
	};
}

#endif
