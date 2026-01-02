#include "my_hash.hpp"

std::array<std::uint64_t, 2> my_hash(const std::uint8_t *data,
                                     std::size_t len) {
  if (data == nullptr) {
    throw std::runtime_error("data is null");
  }

  if (len == 0) {
    throw std::length_error("len is 0");
  }

  absl::Hash<std::string_view> hasher;
  std::string_view data_view(reinterpret_cast<const char*>(data), len);
  
  std::uint64_t hash1 = hasher(data_view);
  std::uint64_t hash2 = absl::Hash<std::size_t>{}(len) ^ hash1;
  
  return {hash1, hash2};
}
