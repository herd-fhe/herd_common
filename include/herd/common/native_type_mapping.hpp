#ifndef HERD_COMMON_NATIVE_TYPE_MAPPING_HPP
#define HERD_COMMON_NATIVE_TYPE_MAPPING_HPP

#include <cstdint>
#include <type_traits>

#include "herd/common/model/data_type.hpp"


namespace herd::common
{
	namespace mapper
	{
		using enum herd::common::DataType;

		template<common::DataType type_key>
		struct NativeTypeMapping
		{
			constexpr static common::DataType key = type_key;
			using native_type = std::false_type;
		};

		template<>
		struct NativeTypeMapping<BIT>
		{
			constexpr static common::DataType key = BIT;
			constexpr static std::size_t bit_size = 1;
			using native_type = bool;
		};

		template<>
		struct NativeTypeMapping<UINT8>
		{
			constexpr static common::DataType key = UINT8;
			constexpr static std::size_t bit_size = 8;
			using native_type = uint8_t;
		};

		template<>
		struct NativeTypeMapping<UINT16>
		{
			constexpr static common::DataType key = UINT16;
			constexpr static std::size_t bit_size = 16;
			using native_type = uint16_t;
		};

		template<>
		struct NativeTypeMapping<UINT32>
		{
			constexpr static common::DataType key = UINT32;
			constexpr static std::size_t bit_size = 32;
			using native_type = uint32_t;
		};

		template<>
		struct NativeTypeMapping<UINT64>
		{
			constexpr static common::DataType key = UINT64;
			constexpr static std::size_t bit_size = 64;
			using native_type = uint64_t;
		};

		template<>
		struct NativeTypeMapping<INT8>
		{
			constexpr static common::DataType key = INT8;
			constexpr static std::size_t bit_size = 8;
			using native_type = int8_t;
		};

		template<>
		struct NativeTypeMapping<INT16>
		{
			constexpr static common::DataType key = INT16;
			constexpr static std::size_t bit_size = 16;
			using native_type = int16_t;
		};

		template<>
		struct NativeTypeMapping<INT32>
		{
			constexpr static common::DataType key = INT32;
			constexpr static std::size_t bit_size = 32;
			using native_type = int32_t;
		};

		template<>
		struct NativeTypeMapping<INT64>
		{
			constexpr static common::DataType key = INT64;
			constexpr static std::size_t bit_size = 64;
			using native_type = int64_t;
		};
	}

	template<common::DataType type_key>
	struct NativeTypeMapping
	{
		constexpr static common::DataType key = mapper::NativeTypeMapping<type_key>::key;
		constexpr static std::size_t bit_size = mapper::NativeTypeMapping<type_key>::bit_size;
		using native_type = typename mapper::NativeTypeMapping<type_key>::native_type;

		static_assert(!std::is_same_v<native_type, std::false_type>);
	};

	unsigned int data_type_to_bit_width(herd::common::DataType type) noexcept;
}

#endif //HERD_COMMON_NATIVE_TYPE_MAPPING_HPP
