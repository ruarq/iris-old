#ifndef IRIS_AST_BINARY_EXPR_HPP
#define IRIS_AST_BINARY_EXPR_HPP

#include "AcceptExprVisitor.hpp"
#include "Expr.hpp"
#include "common.hpp"

namespace iris::ast {
	struct BinaryExpr : public AcceptExprVisitor<BinaryExpr> {
	public:
		enum Op {
			Add,
			Sub,
			Mul,
			Div,
			Mod,
		};

	public:
		IRIS_CONSTRUCTOR
		BinaryExpr(std::unique_ptr<Expr> &&left, Op op, std::unique_ptr<Expr> &&right);

	public:
		std::unique_ptr<Expr> left;
		Op op;
		std::unique_ptr<Expr> right;
	};

	IRIS_NODISCARD auto to_string(BinaryExpr::Op op) -> std::string_view;
}

#endif
