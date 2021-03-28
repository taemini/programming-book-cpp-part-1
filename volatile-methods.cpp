#include <cstdio>

struct Distillate {
  int apply() volatile {
    return ++applications;
  }
  private:
    int applications{};
};

int main() {
  volatile Distillate ethanol;
  printf("%d Tequila\n", ethanol.apply());
  printf("%d Tequila\n", ethanol.apply());
  printf("%d Tequila\n", ethanol.apply());
  printf("Floor!");
}