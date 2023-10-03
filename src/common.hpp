#ifndef IRIS_COMMON_HPP
#define IRIS_COMMON_HPP

#include <algorithm>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

#define IRIS_CONSTRUCTOR IRIS_NODISCARD explicit
#define IRIS_NODISCARD [[nodiscard]]
#define IRIS_VOIDP_SIZE (sizeof(void *))

namespace iris {
	using usz = unsigned long;
}

#endif
