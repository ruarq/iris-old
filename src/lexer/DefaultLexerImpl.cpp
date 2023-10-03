#include "DefaultLexerImpl.hpp"

namespace iris::lexer {
	auto DefaultLexerImpl::lex() -> Token {
		return Token{ Token::Kind::Eof, 0 };
	}
}
