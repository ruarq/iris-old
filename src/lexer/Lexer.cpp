#include "Lexer.hpp"

namespace iris::lexer {
	Lexer::Lexer(LexerImpl &impl)
		: _impl{ impl } {
	}

	auto Lexer::current() -> Token {
		return peek(0);
	}

	auto Lexer::peek(const usz amount) -> Token {
		require_buffer_size(amount + 1);
		return _buffer[amount];
	}

	auto Lexer::consume() -> Token {
		const auto token = current();
		_buffer.pop_front();
		return token;
	}

	auto Lexer::require_buffer_size(const usz size) -> void {
		if (_buffer.size() < size) {
			fill_buffer(std::max(size - _buffer.size(), buffer_size));
		}
	}

	auto Lexer::fill_buffer(const usz amount) -> void {
		for (usz i = 0; i < amount; ++i) {
			_buffer.push_back(_impl.lex());
		}
	}
}
