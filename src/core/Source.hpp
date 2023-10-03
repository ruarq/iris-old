#ifndef IRIS_CORE_SOURCE_HPP
#define IRIS_CORE_SOURCE_HPP

#include "common.hpp"

namespace iris::core {
	struct Source {
	public:
		IRIS_CONSTRUCTOR Source(std::string &&filename, std::string &&content);

	public:
		IRIS_NODISCARD auto filename() const -> std::string_view;
		IRIS_NODISCARD auto content() const -> std::string_view;

	private:
		std::string _filename;
		std::string _content;
	};
}

#endif
