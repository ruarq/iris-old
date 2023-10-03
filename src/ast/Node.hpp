#ifndef IRIS_AST_NODE_HPP
#define IRIS_AST_NODE_HPP

#include "common.hpp"

namespace iris::ast {
	struct Node {
	public:
		virtual ~Node() = default;
	};
}

#endif
