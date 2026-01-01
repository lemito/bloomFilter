#pragma once

#include <cstdint>
#include <vector>
#include "my_hash.hpp"

class BloomFilter {
  std::uint8_t num_hashes;
  std::vector<bool> bits;

public:
  BloomFilter(const std::uint64_t size, const std::uint8_t num_hashes)
      : bits(size), num_hashes(num_hashes) {}

  constexpr bool add(const uint8_t *const data, const std::size_t len);
  constexpr bool possiblyContains(const uint8_t *const data,
                                  const std::size_t len) const;
};
