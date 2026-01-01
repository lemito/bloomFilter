#pragma once

#include "absl/hash/hash.h"
#include <array>
#include <cstdint>
#include <stdexcept>

std::array<std::uint64_t, 2> my_hash(const std::uint8_t *data, std::size_t len);
