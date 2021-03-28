#include <cstdio>

int main() {
  auto year{2019};
  auto& year_ref = year;
  auto* year_pref = &year;
  printf("%d\n", year);
  printf("%p\n", &year);
  printf("%p\n", &year_ref);
  printf("%d\n", *year_pref);
}