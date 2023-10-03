#ifndef IRIS_LEXER_LEXER_IMPL_HPP
#define IRIS_LEXER_LEXER_IMPL_HPP

#include "Token.hpp"
#include "common.hpp"

namespace iris::lexer {
	struct LexerImpl {
	public:
		virtual ~LexerImpl() = default;

	public:
		IRIS_NODISCARD virtual auto lex() -> Token = 0;
	};
}

#endif
