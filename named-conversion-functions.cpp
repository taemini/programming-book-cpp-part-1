#include <cstdio>
#include <stdexcept>

void carbon_thaw(const int& encased_solo) {
  // encased_solo++;
  auto& hibernation_sick_solo = const_cast<int&>(encased_solo);
  hibernation_sick_solo++;
}

short increment_as_short(void* target) {
  auto as_short = static_cast<short*>(target);
  *as_short = *as_short + 1;
  return *as_short;
}

template <typename To, typename From>
To narrow_cast(From value) {
  const auto converted = static_cast<To>(value);
  const auto backwards = static_cast<From>(converted);
  if (value != backwards) throw std::runtime_error{"Narrowed!"};
  return converted;
}

template <typename T>
T mean(const T* values, size_t length) {
  T result{};
  for (size_t i{}; i < length; i++) {
    result += values[i];
  }
  return result / length;
}

int main() {
  int a = 1;
  carbon_thaw(a);
  printf("%d\n", a);

  int beast{665};
  printf("%d\n", beast);
  auto mark_of_the_beast = increment_as_short(&beast);
  printf("%d is the mark_of_the_beast.\n", mark_of_the_beast);

  float f = 3.3;
  auto f_ptr_as_short = static_cast<double>(f);

  // test narrow_cast
  int perfect{496};
  const auto perfect_short = narrow_cast<short>(perfect);
  printf("perfect_short: %d\n", perfect_short);
  try {
    int cyclic{142857};
    const auto cyclic_short = narrow_cast<short>(cyclic);
    printf("cyclic_short: %d\n", cyclic_short);
  } catch (const std::runtime_error& e) {
    printf("Exception: %s\n", e.what());
  }

  // test mean
  const double nums_d[]{1.0, 2.0, 3.0, 4.0};
  const auto result_d = mean(nums_d, 4);
  printf("double: %f\n", result_d);

  const float nums_f[]{1.0f, 2.0f, 3.0f, 4.0f};
  const auto result_f = mean<float>(nums_f, 4);
  printf("float: %f\n", result_f);

  const size_t nums_c[]{1, 2, 3, 4};
  const auto result_c = mean<size_t>(nums_c, 4);
  printf("size_t: %zu\n", result_c);
}
