#include "filter.hpp"
#include <iostream>
#include <string_view>

int main() {
  BloomFilter filter(128, 10);

  constexpr std::string_view test_string = "meow_UwU";
  auto data = test_string.data();
  auto len = test_string.size();

  filter.add(reinterpret_cast<const uint8_t *const>(data), len);

  if (filter.possiblyContains(reinterpret_cast<const uint8_t *const>(data),
                              len)) {
    std::cout << test_string << " contains in filter\n";
  } else {
    std::cout << test_string << " not contains in filter\n";
  }

  return 0;
}
