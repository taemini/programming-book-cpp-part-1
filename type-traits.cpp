#include <cstdint>
#include <cstdio>
#include <type_traits>

constexpr const char* as_str(bool x) { return x ? "True" : "False"; }

int main() {
  printf("%s\n", as_str(std::is_integral<int>::value));        // True
  printf("%s\n", as_str(std::is_integral<const int>::value));  // True
  printf("%s\n", as_str(std::is_integral<char>::value));       // True
  printf("%s\n", as_str(std::is_integral<uint64_t>::value));   // True
  printf("%s\n", as_str(std::is_integral<int&>::value));       // False
  printf("%s\n", as_str(std::is_integral<int*>::value));       // False
  printf("%s\n", as_str(std::is_integral<float>::value));      // False
}