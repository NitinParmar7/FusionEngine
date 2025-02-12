#pragma once
#include <cstdint>

// C++11 introduced constexpr and using-aliases.
// Here, we define an Entity as a 32-bit unsigned integer.
// 'constexpr' ensures that INVALID_ENTITY is a compile-time constant.
using Entity = std::uint32_t;
constexpr Entity INVALID_ENTITY = 0xFFFFFFFF;
