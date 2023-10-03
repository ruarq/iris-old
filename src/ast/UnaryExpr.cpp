#include "UnaryExpr.hpp"

namespace iris::ast {
	UnaryExpr::UnaryExpr(const Op op, std::unique_ptr<Expr> &&expr)
		: op{ op }
		, expr{ std::move(expr) } {
	}
}
