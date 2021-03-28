#include <cstdio>
#include "exercise-8-1-fibonacci.h"

int main() {
  for (const auto i : FibonacciRange{5000}) {
    printf("%d ", i);
  }
}