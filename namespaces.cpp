#include <cstdio>

namespace BroopKidron13::Shaltanac {
  enum class Color {
    Mauve,
    Pink,
    Russet
  };
}

int main() {
  const auto shaltanac_grass{ BroopKidron13::Shaltanac::Color::Russet };
  printf("%d\n", shaltanac_grass);
  if (shaltanac_grass == BroopKidron13::Shaltanac::Color::Russet) {
    printf("The other Shalta");
  }
}