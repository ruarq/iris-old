#include <fmt/format.h>

#include "ast/ast.hpp"
#include "common.hpp"
#include "core/Source.hpp"
#include "core/SymbolMap.hpp"
#include "lexer/DefaultLexerImpl.hpp"
#include "lexer/Lexer.hpp"
#include "parser/Parser.hpp"

auto main(int argc, char **argv) -> int {
	using namespace iris::ast;

	if (argc != 2) {
		fmt::print("Usage: iris <expr>\n");
		return 1;
	}

	iris::core::Source source{ "<internal>", std::string{ argv[1] } };

	iris::core::SymbolMap symbols;
	iris::lexer::DefaultLexerImpl lexer_impl{ source, symbols };
	iris::lexer::Lexer lexer{ lexer_impl };
	iris::parser::Parser parser{ lexer, symbols };

	auto expr = parser.parse_expr();
	fmt::print("Result: {}\n", expr->eval());

	return 0;
}
