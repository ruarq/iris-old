#ifndef IRIS_LEXER_DEFAULT_LEXER_IMPL_HPP
#define IRIS_LEXER_DEFAULT_LEXER_IMPL_HPP

#include "LexerImpl.hpp"
#include "Token.hpp"
#include "common.hpp"
#include "core/Source.hpp"
#include "core/SymbolMap.hpp"
#include "util/char_helpers.hpp"

namespace iris::lexer {
	struct DefaultLexerImpl : public LexerImpl {
	public:
		IRIS_CONSTRUCTOR DefaultLexerImpl(const core::Source &source, core::SymbolMap &symbols);

	public:
		IRIS_NODISCARD auto lex() -> Token override;

	private:
		IRIS_NODISCARD auto simple_token(Token::Kind kind, usz size) -> Token;
		IRIS_NODISCARD auto lex_number() -> Token;

		IRIS_NODISCARD auto is_eof() const -> bool;

		IRIS_NODISCARD auto current() const -> char;
		IRIS_NODISCARD auto peek(usz amount) const -> char;
		auto consume() -> char;
		auto advance(usz amount) -> void;

	private:
		const core::Source &_source;
		core::SymbolMap &_symbols;
		usz _current;
	};
}

#endif
