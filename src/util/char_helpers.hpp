#ifndef IRIS_UTIL_CHAR_HELPERS_HPP
#define IRIS_UTIL_CHAR_HELPERS_HPP

#include "common.hpp"
namespace iris {
	IRIS_NODISCARD constexpr auto is_digit(const char c) -> bool {
		return c >= '0' && c <= '9';
	}

	IRIS_NODISCARD constexpr auto is_letter(const char c) -> bool {
		return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
	}

	/**
	 * @brief Check whether a character is valid in a identifier or not
	 * @note Identifiers may not start with a digit, even if this function
	 * returns true for digits
	 */
	IRIS_NODISCARD constexpr auto is_identifier(const char c) -> bool {
		return is_letter(c) || is_digit(c) || c == '_';
	}
}

#endif
