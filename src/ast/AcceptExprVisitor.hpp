#ifndef IRIS_AST_ACCEPT_EXPR_VISITOR_HPP
#define IRIS_AST_ACCEPT_EXPR_VISITOR_HPP

#include "Expr.hpp"
#include "ExprVisitor.hpp"
#include "common.hpp"

namespace iris::ast {
	template<typename TClass>
	struct AcceptExprVisitor : public Expr {
	public:
		auto accept(ExprVisitor &visitor) -> void {
			visitor.visit(*(TClass *)this);
		}
	};
}

#endif
