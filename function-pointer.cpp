#include <cstdio>

float add(float a, int b) {
  return a + b;
}
float subtract(float a, int b) {
  return a - b;
}

int main() {
  const float first{100};
  const int second{20};

  float(*operation)(float, int){};
  printf("operation initialized to %p\n", operation);

  operation = &add; // & can be omitted (optional)
  printf("&add = %p\n", operation);
  printf("%g + %d = %g\n", first, second, operation(first, second));

  operation = subtract;
  printf("&subtract = %p\n", operation);
  printf("%g - %d = %g\n", first, second, operation(first, second));
}