#include "Source.hpp"

namespace iris::core {
	Source::Source(std::string &&filename, std::string &&content)
		: _filename{ filename }
		, _content{ content } {
	}

	auto Source::filename() const -> std::string_view {
		return _filename;
	}

	auto Source::content() const -> std::string_view {
		return _content;
	}
}
