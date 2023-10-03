#include "DefaultLexerImpl.hpp"

namespace iris::lexer {
	DefaultLexerImpl::DefaultLexerImpl(const core::Source &source, core::SymbolMap &symbols)
		: _source{ source }
		, _symbols{ symbols }
		, _current{ 0 } {
	}

	auto DefaultLexerImpl::lex() -> Token {
		while (!is_eof()) {
			switch (current()) {
				case ' ':
				case '\t':
				case '\n': break;

				case '0' ... '9': return lex_number();
				case '(': return simple_token(Token::Kind::LParen, 1);
				case ')': return simple_token(Token::Kind::RParen, 1);
				case '+': return simple_token(Token::Kind::Plus, 1);
				case '-': return simple_token(Token::Kind::Minus, 1);
				case '*': return simple_token(Token::Kind::Star, 1);
				case '/': return simple_token(Token::Kind::Slash, 1);
				case '%': return simple_token(Token::Kind::Percent, 1);
				default: return simple_token(Token::Kind::Error, 1);
			}

			consume();
		}

		return simple_token(Token::Kind::Eof, 0);
	}

	auto DefaultLexerImpl::simple_token(const Token::Kind kind, const usz size) -> Token {
		auto start = _current;
		advance(size);
		const std::string symbol{ _source.content().substr(start, size) };
		return Token{ kind, _symbols.insert(symbol) };
	}

	auto DefaultLexerImpl::lex_number() -> Token {
		std::string literal;
		while (!is_eof() && is_digit(current())) {
			literal += consume();
		}

		return Token{ Token::Kind::LInteger, _symbols.insert(literal) };
	}

	auto DefaultLexerImpl::is_eof() const -> bool {
		return _current >= _source.content().size();
	}

	auto DefaultLexerImpl::current() const -> char {
		return peek(0);
	}

	auto DefaultLexerImpl::peek(const usz amount) const -> char {
		return _source.content()[_current + amount];
	}

	auto DefaultLexerImpl::consume() -> char {
		const auto c = current();
		++_current;
		return c;
	}

	auto DefaultLexerImpl::advance(const usz amount) -> void {
		for (usz i = 0; i < amount; ++i) {
			consume();
		}
	}
}
