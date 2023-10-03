#ifndef IRIS_AST_EXPR_HPP
#define IRIS_AST_EXPR_HPP

#include "ExprVisitor.hpp"
#include "Node.hpp"
#include "common.hpp"

namespace iris::ast {
	struct Expr : public Node {
	public:
		virtual auto accept(ExprVisitor &visitor) -> void = 0;
	};
}

#endif
