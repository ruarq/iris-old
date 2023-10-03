#include "Parser.hpp"

namespace iris::parser {
	std::unordered_map<lexer::Token::Kind, std::pair<ast::BinaryExpr::Op, usz>>
		Parser::binary_op_info = {
			{lexer::Token::Kind::Plus,		{ ast::BinaryExpr::Op::Add, 1 }},
			{ lexer::Token::Kind::Minus,	 { ast::BinaryExpr::Op::Sub, 1 }},
			{ lexer::Token::Kind::Star,	{ ast::BinaryExpr::Op::Mul, 2 }},
			{ lexer::Token::Kind::Slash,	 { ast::BinaryExpr::Op::Div, 2 }},
			{ lexer::Token::Kind::Percent, { ast::BinaryExpr::Op::Mod, 2 }}
	};

	auto Parser::is_binary_op(const lexer::Token::Kind kind) -> bool {
		return binary_op_info.contains(kind);
	}

	auto Parser::to_binary_op(const lexer::Token::Kind kind) -> ast::BinaryExpr::Op {
		return binary_op_info[kind].first;
	}

	auto Parser::get_binding_strength(const lexer::Token::Kind kind) -> usz {
		if (!is_binary_op(kind)) {
			return 0;
		}

		return binary_op_info[kind].second;
	}

	Parser::Parser(lexer::Lexer &lexer, core::SymbolMap &symbols)
		: _lexer{ lexer }
		, _symbols{ symbols } {
	}

	auto Parser::parse_expr() -> std::unique_ptr<ast::Expr> {
		return parse_binary_expr(1);
	}

	auto Parser::parse_factor_expr() -> std::unique_ptr<ast::Expr> {
		switch (current().kind) {
			case lexer::Token::Kind::LParen: return parse_grouping_expr();
			case lexer::Token::Kind::LInteger: return parse_value_expr();
			case lexer::Token::Kind::Minus: return parse_unary_expr();
			default: break;
		}

		throw std::runtime_error{ "expected factor" };
	}

	auto Parser::parse_binary_expr(const usz min_binding_strength) -> std::unique_ptr<ast::Expr> {
		auto left = parse_factor_expr();

		while (!is_eof() && is_binary_op(current().kind)) {
			auto binding_strength = get_binding_strength(current().kind);
			if (binding_strength < min_binding_strength) {
				break;
			}
			auto token_op = consume();

			++binding_strength;

			auto right = parse_binary_expr(binding_strength);

			left = std::make_unique<ast::BinaryExpr>(std::move(left),
				to_binary_op(token_op.kind),
				std::move(right));
		}

		return left;
	}

	auto Parser::parse_unary_expr() -> std::unique_ptr<ast::UnaryExpr> {
		auto token_op = consume(lexer::Token::Kind::Minus);
		auto expr = parse_factor_expr();
		return std::make_unique<ast::UnaryExpr>(ast::UnaryExpr::Op::Negate, std::move(expr));
	}

	auto Parser::parse_grouping_expr() -> std::unique_ptr<ast::GroupingExpr> {
		consume(lexer::Token::Kind::LParen);
		auto expr = parse_expr();
		consume(lexer::Token::Kind::RParen);
		return std::make_unique<ast::GroupingExpr>(std::move(expr));
	}

	auto Parser::parse_value_expr() -> std::unique_ptr<ast::ValueExpr> {
		auto token_value = consume(lexer::Token::Kind::LInteger);
		auto string_value = _symbols.get(token_value.symbol);
		int value = 0;
		std::from_chars(string_value.data(), string_value.data() + string_value.size(), value);
		return std::make_unique<ast::ValueExpr>(value);
	}

	auto Parser::is_eof() -> bool {
		return current().kind == lexer::Token::Kind::Eof;
	}

	auto Parser::current() -> lexer::Token {
		return _lexer.current();
	}

	auto Parser::peek(const usz amount) -> lexer::Token {
		return _lexer.peek(amount);
	}

	auto Parser::consume() -> lexer::Token {
		return _lexer.consume();
	}

	auto Parser::consume(const lexer::Token::Kind kind) -> lexer::Token {
		if (current().kind != kind) {
			throw std::runtime_error{ "Unexpected token!" };
		}

		return consume();
	}
}
