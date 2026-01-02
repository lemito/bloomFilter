#include "filter.hpp"

constexpr std::uint64_t nthHash(std::uint8_t n, std::uint64_t hashA,
                                std::uint64_t hashB, std::uint64_t filterSize) {
  return (hashA + n * hashB) % filterSize;
}

bool BloomFilter::add(const uint8_t *const data,
                      const std::size_t len) {
  auto hash_res = my_hash(data, len);

  for (std::size_t n = 0; n < num_hashes; n++) {
    bits[nthHash(n, hash_res[0], hash_res[1], bits.size())] = true;
  }

  return true;
}

bool BloomFilter::possiblyContains(const uint8_t *const data,
                                   const std::size_t len) const {
  auto hash_res = my_hash(data, len);

  for (std::size_t n = 0; n < num_hashes; n++) {
    if (!bits[nthHash(n, hash_res[0], hash_res[1], bits.size())]) {
      return false;
    }
  }

  return true;
}
