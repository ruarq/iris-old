#ifndef IRIS_PARSER_PARSER_HPP
#define IRIS_PARSER_PARSER_HPP

#include <charconv>

#include "ast/ast.hpp"
#include "common.hpp"
#include "core/SymbolMap.hpp"
#include "lexer/Lexer.hpp"

namespace iris::parser {
	struct Parser {
	public:
		enum class Associativity {
			Left,
			Right
		};

	public:
		static std::unordered_map<lexer::Token::Kind, std::pair<ast::BinaryExpr::Op, usz>>
			binary_op_info;

		static auto is_binary_op(lexer::Token::Kind kind) -> bool;
		static auto to_binary_op(lexer::Token::Kind kind) -> ast::BinaryExpr::Op;
		static auto get_binding_strength(lexer::Token::Kind kind) -> usz;

	public:
		IRIS_CONSTRUCTOR Parser(lexer::Lexer &lexer, core::SymbolMap &symbols);

	public:
		IRIS_NODISCARD auto parse_expr() -> std::unique_ptr<ast::Expr>;

	private:
		IRIS_NODISCARD auto parse_factor_expr() -> std::unique_ptr<ast::Expr>;
		IRIS_NODISCARD auto parse_binary_expr(usz min_binding_strength)
			-> std::unique_ptr<ast::Expr>;
		IRIS_NODISCARD auto parse_unary_expr() -> std::unique_ptr<ast::UnaryExpr>;
		IRIS_NODISCARD auto parse_grouping_expr() -> std::unique_ptr<ast::GroupingExpr>;
		IRIS_NODISCARD auto parse_value_expr() -> std::unique_ptr<ast::ValueExpr>;

		IRIS_NODISCARD auto is_eof() -> bool;
		IRIS_NODISCARD auto current() -> lexer::Token;
		IRIS_NODISCARD auto peek(usz amount) -> lexer::Token;
		auto consume() -> lexer::Token;
		auto consume(lexer::Token::Kind kind) -> lexer::Token;

	private:
		lexer::Lexer &_lexer;
		core::SymbolMap &_symbols;
	};
}

#endif
