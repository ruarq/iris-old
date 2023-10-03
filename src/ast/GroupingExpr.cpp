#include "GroupingExpr.hpp"

namespace iris::ast {
	GroupingExpr::GroupingExpr(std::unique_ptr<Expr> &&expr)
		: expr{ std::move(expr) } {
	}
}
