#ifndef IRIS_AST_BINARY_EXPR_HPP
#define IRIS_AST_BINARY_EXPR_HPP

#include "Expr.hpp"
#include "common.hpp"

namespace iris::ast {
	struct BinaryExpr : public Expr {
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
		auto eval() -> int override {
			switch (op) {
				case Op::Add: return left->eval() + right->eval();
				case Op::Sub: return left->eval() - right->eval();
				case Op::Mul: return left->eval() * right->eval();
				case Op::Div: return left->eval() / right->eval();
				case Op::Mod: return left->eval() % right->eval();
			}
		}

	public:
		std::unique_ptr<Expr> left;
		Op op;
		std::unique_ptr<Expr> right;
	};
}

#endif
