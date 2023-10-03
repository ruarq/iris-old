#include "BinaryExpr.hpp"

namespace iris::ast {
	BinaryExpr::BinaryExpr(std::unique_ptr<Expr> &&left, const Op op, std::unique_ptr<Expr> &&right)
		: left{ std::move(left) }
		, op{ op }
		, right{ std::move(right) } {
	}
}
