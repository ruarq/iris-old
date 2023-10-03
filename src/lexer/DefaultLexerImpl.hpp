#ifndef IRIS_LEXER_DEFAULT_LEXER_IMPL_HPP
#define IRIS_LEXER_DEFAULT_LEXER_IMPL_HPP

#include "LexerImpl.hpp"
#include "Token.hpp"
#include "common.hpp"
#include "util/char_helpers.hpp"

namespace iris::lexer {
	struct DefaultLexerImpl : public LexerImpl {
	public:
		IRIS_NODISCARD auto lex() -> Token override;
	};
}

#endif
