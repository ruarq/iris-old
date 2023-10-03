#include "Token.hpp"

namespace iris::lexer {
	Token::Token(const Kind kind, const core::Symbol symbol)
		: kind{ kind }
		, symbol{ symbol } {
	}
}
