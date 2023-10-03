#include <fmt/format.h>

#include "common.hpp"
#include "core/SymbolMap.hpp"
#include "lexer/DefaultLexerImpl.hpp"
#include "lexer/Lexer.hpp"

auto main() -> int {
	using namespace iris::lexer;
	DefaultLexerImpl lexer_impl;
	Lexer lexer{ lexer_impl };
	fmt::print("{}\n", (iris::usz)lexer.current().kind);
	return 0;
}
