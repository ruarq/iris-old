#include "UnaryExpr.hpp"

namespace iris::ast {
	UnaryExpr::UnaryExpr(const Op op, std::unique_ptr<Expr> &&expr)
		: op{ op }
		, expr{ std::move(expr) } {
	}

	auto to_string(const UnaryExpr::Op op) -> std::string_view {
		switch (op) {
			case UnaryExpr::Op::Negate: return "-";
		}
	}
}
