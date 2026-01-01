#include "my_hash.hpp"
#include <cstring>
#include <exception>
#include <iostream>

int main() {
  char test_str[] = "meow_user";
  std::cout << test_str << '\n';
  try {
    const auto res =
        my_hash(reinterpret_cast<uint8_t *>(test_str), std::strlen(test_str));
    std::cout << (res[0]) << " " << (res[1]);
  } catch (const std::exception& e) {
    std::cout << e.what();
  }
  return 0;
}
