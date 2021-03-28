#include <cstdio>
#include <functional>

template <typename Fn, typename In, typename Out>
constexpr Out fold(Fn function, In* input, size_t length, Out initial) {
  auto result = initial;
  for (size_t i{}; i<length; i++) {
    result = function(result, input[i]);
  }
  return result;
}

int main() {
  int data[]{100,200,300,400,500};
  size_t data_len = 5;
  auto sum = fold([](auto x, auto y){ return x + y; }, data, data_len, 0);
  printf("sum: %d\n", sum);
}