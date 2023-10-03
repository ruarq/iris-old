#include "AstGraphDump.hpp"

namespace iris::util {
	AstGraphDump::AstGraphDump()
		: _current_id{ 0 } {
	}

	auto AstGraphDump::dump(ast::Expr &expr) -> void {
		fmt::print("digraph {{\n");
		expr.accept(*this);
		fmt::print("}}\n");
	}

	auto AstGraphDump::visit(ast::BinaryExpr &binary_expr) -> void {
		auto id = push_id();
		add_node(id, ast::to_string(binary_expr.op));

		binary_expr.left->accept(*this);
		binary_expr.right->accept(*this);

		auto rhs_id = pop_id();
		auto lhs_id = pop_id();

		connect_nodes(id, { lhs_id, rhs_id });
	}

	auto AstGraphDump::visit(ast::UnaryExpr &unary_expr) -> void {
		auto id = push_id();
		add_node(id, ast::to_string(unary_expr.op));

		unary_expr.expr->accept(*this);

		auto expr_id = pop_id();

		connect_nodes(id, { expr_id });
	}

	auto AstGraphDump::visit(ast::GroupingExpr &grouping_expr) -> void {
		grouping_expr.expr->accept(*this);
	}

	auto AstGraphDump::visit(ast::ValueExpr &value_expr) -> void {
		auto id = push_id();
		add_node(id, fmt::format("{}", value_expr.value));
	}

	auto AstGraphDump::push_id() -> usz {
		_id_stack.push(_current_id);
		return _current_id++;
	}

	auto AstGraphDump::pop_id() -> usz {
		auto id = _id_stack.top();
		_id_stack.pop();
		return id;
	}

	auto AstGraphDump::add_node(const usz id, std::string_view label) -> void {
		fmt::print("node_{} [label=\"{}\"]\n", id, label);
	}

	auto AstGraphDump::connect_nodes(const usz from_id, const std::vector<usz> &to_ids) -> void {
		fmt::print("node_{} -> ", from_id);

		if (to_ids.empty()) {
			throw std::invalid_argument{
				"iris::util::AstGraphDump::connect_nodes() : to_ids is empty"
			};
		}

		auto itr = to_ids.begin();
		fmt::print("node_{}", *itr);
		++itr;
		while (itr < to_ids.end()) {
			fmt::print(", node_{}", *itr);
			++itr;
		}

		fmt::print("\n");
	}
}
