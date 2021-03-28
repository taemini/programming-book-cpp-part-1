#include <cstdio>
#include "exercise-8-2-prime.h"

int main() {
  for (const int i: PrimeNumberRange{10000}) {
    printf("%d ", i);
  }
}