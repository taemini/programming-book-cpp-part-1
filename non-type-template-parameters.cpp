#include <stdexcept>

template <typename T, size_t Length>
T& get(T (&arr)[Length], size_t index) {
  if (index >= Length) throw std::out_of_range{"Out of range"};
  return arr[index];
}

int main() {
  int arr[10]{1, 2, 3, 4, 5};
  printf("%d", get(arr, 3));
}