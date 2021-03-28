#include <cstdio>
#include <stdexcept>

template <typename To, typename From>
struct NarrowCaster {
  To cast(From value) {
    const auto converted = static_cast<To>(value);
    const auto backwards = static_cast<From>(converted);
    if (value != backwards) throw std::runtime_error{"Narrowed!"};
    return converted;
  }
};

template <typename From>
using short_caster = NarrowCaster<short, From>;

int main() {
  try {
    short_caster<int> caster;
    const auto cyclic_short = caster.cast(142857);
  } catch (const std::runtime_error& e) {
    printf("Exception: %s\n", e.what());
  }
}