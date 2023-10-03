#include "BinaryExpr.hpp"

namespace iris::ast {
	BinaryExpr::BinaryExpr(std::unique_ptr<Expr> &&left, const Op op, std::unique_ptr<Expr> &&right)
		: left{ std::move(left) }
		, op{ op }
		, right{ std::move(right) } {
	}

	auto to_string(const BinaryExpr::Op op) -> std::string_view {
		switch (op) {
			case BinaryExpr::Op::Add: return "+";
			case BinaryExpr::Op::Sub: return "-";
			case BinaryExpr::Op::Mul: return "*";
			case BinaryExpr::Op::Div: return "/";
			case BinaryExpr::Op::Mod: return "%";
		}
	}
}
