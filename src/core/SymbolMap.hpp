#ifndef IRIS_CORE_SYMBOL_MAP_HPP
#define IRIS_CORE_SYMBOL_MAP_HPP

#include "Symbol.hpp"
#include "VectorMap.hpp"

namespace iris::core {
	using SymbolMap = VectorMap<Symbol, std::string>;
}

#endif
