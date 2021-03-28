#include <cstdio>

// void trainwreck(const char* read_only) {
//   auto as_unsigned = (unsigned char*)read_only;
//   *as_unsigned = 'b';
// }

void trainwreck(const char* read_only) {
  auto as_unsigned = reinterpret_cast<unsigned char*>(read_only);
  *as_unsigned = 'b';
}

int main() {
  auto ezra = "Ezra";
  printf("Before trainwreck: %s\n", ezra);
  trainwreck(ezra);
  printf("After trainwreck: %s\n", ezra);
}