#include <cstdio>
#include <stdexcept>

[[noreturn]] void pitcher() {
  throw std::runtime_error{ "Knuckleball." };
}

int main() {
  int a = 2;
  switch(a) {
    case 1:
      if (a > 1) {
        printf("aaaaaaaaaaaaaa\n");
      }
      [[fallthrough]];
    case 2: printf("ddddd\n");
  }

  try {
    pitcher();
  } catch(const std::exception& e) {
    printf("Exception: %s\n", e.what());
  }
}