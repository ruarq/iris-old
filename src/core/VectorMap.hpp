#ifndef IRIS_CORE_VECTOR_MAP_HPP
#define IRIS_CORE_VECTOR_MAP_HPP

#include <unordered_map>

#include "common.hpp"

namespace iris::core {
	template<typename TId, typename TValue>
	struct VectorMap {
	public:
		IRIS_NODISCARD auto insert(const TValue &value) -> TId {
			if (!_map.contains(value)) {
				_map.emplace(value, _current_id);
				_values.push_back(value);
				return _current_id++;
			}

			return _map[value];
		}

		IRIS_NODISCARD auto get(const TId id) -> std::string {
			return _values[id];
		}

	private:
		std::unordered_map<TValue, TId> _map;
		std::vector<TValue> _values;

		TId _current_id{};
	};
}

#endif
