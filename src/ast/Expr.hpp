#ifndef IRIS_AST_EXPR_HPP
#define IRIS_AST_EXPR_HPP

#include "Node.hpp"
#include "common.hpp"

namespace iris::ast {
	struct Expr : public Node {
	public:
		virtual auto eval() -> int = 0;
	};
}

#endif
