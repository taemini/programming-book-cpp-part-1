#include <cstdio>
#include <cstdint>

bool double_return_overflow(uint8_t& x) {
  const auto original = x;
  x *= 2;
  return original > x;
}
int main() {
  uint8_t x{1};
  printf("uint8_t:\n===\n");
  while(!double_return_overflow(x)) {
    printf("%u ", x);
  }
  printf("\n\n");

  uint8_t y{1};
  printf("uint8_t:\n===\n");
  do {
    printf("%u ", y);
  } while(!double_return_overflow(y));
}