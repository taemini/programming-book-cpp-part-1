#include <cstdio>

int step_function(int x) {
  int result = 0;
  if (x > 0)
    result = 1;
  else if (x < 0)
    result = -1;
  return result;
}

int main() {                  // main은 entry point
  printf("Hello, world!\n");  // printf is defined in cstdio

  int x = 0;
  if (x > 0)
    printf("Positive\n");
  else if (x < 0)
    printf("Negative\n");
  else
    printf("Zero\n");

  int value1 = step_function(100);
  int value2 = step_function(0);
  int value3 = step_function(-10);
  printf("%d, %d, %d\n", value1, value2, value3);

  return 0;  // is optional (only in the main function)
}