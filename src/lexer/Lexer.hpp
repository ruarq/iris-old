#ifndef IRIS_LEXER_LEXER_HPP
#define IRIS_LEXER_LEXER_HPP

#include <deque>

#include "LexerImpl.hpp"
#include "Token.hpp"
#include "common.hpp"

namespace iris::lexer {
	struct Lexer {
	public:
		static constexpr usz buffer_size = 1024;

	public:
		IRIS_CONSTRUCTOR Lexer();
		IRIS_CONSTRUCTOR Lexer(LexerImpl &impl);

	public:
		IRIS_NODISCARD auto current() -> Token;
		IRIS_NODISCARD auto peek(usz amount) -> Token;
		IRIS_NODISCARD auto consume() -> Token;

	private:
		auto require_buffer_size(usz size) -> void;
		auto fill_buffer(usz amount) -> void;

	private:
		LexerImpl &_impl;
		std::deque<Token> _buffer;
	};
}

#endif
