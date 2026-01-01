#include "my_hash.hpp"

std::array<std::uint64_t, 2> my_hash(const std::uint8_t *data,
                                     std::size_t len) {
  if (data == nullptr) {
    throw std::runtime_error("data is null");
  }

  if (len == 0) {
    throw std::length_error("len is 0");
  }

  absl::HashState state = absl::HashState::Create(&state);
  state = absl::HashState::combine_contiguous(
      std::move(state), reinterpret_cast<const unsigned char *>(data), len);

  std::array<uint64_t, 2> hashValue;

  auto hasher = absl::Hash<std::array<uint64_t, 2>>();

  std::uintptr_t ptr_val = reinterpret_cast<std::uintptr_t>(data);
  hashValue = {absl::Hash<std::uintptr_t>{}(ptr_val),
               absl::Hash<std::size_t>{}(len)};

  return hashValue;
}
