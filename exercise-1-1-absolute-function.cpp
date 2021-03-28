#include <cstdio>

int absolute_value(int x) {
  int result = x;
  if (x < 0) {
    result = result * -1;
  }
  return result;
}

int sum(int x, int y) {
  int result = x + y;
  return result;
}

int main() {
  int my_num = 10;
  int a = 3;
  int b = 4;

  printf("The absolute value of %d is %d\n", my_num, absolute_value(my_num));
  printf("The sum of %d and %d is %d\n", a, b, sum(a, b));

  return 0;
}