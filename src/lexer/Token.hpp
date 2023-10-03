#ifndef IRIS_LEXER_TOKEN_HPP
#define IRIS_LEXER_TOKEN_HPP

#include "common.hpp"
#include "core/Symbol.hpp"

namespace iris::lexer {
	struct Token {
	public:
		enum class Kind {
			LParen,	   ///< (
			RParen,	   ///< )

			Plus,		///< +
			Minus,		///< -
			Star,		///< *
			Slash,		///< /
			Percent,	///< %

			LInteger,	 ///< integer literal

			Error,	  ///< for unrecognized tokens
			Eof,	  ///< end of file/input
			Count,
		};

	public:
		IRIS_CONSTRUCTOR Token(Kind kind, core::Symbol symbol);

	public:
		Kind kind;
		core::Symbol symbol;
	};
}

#endif
