#include <cstdio>
#include <stdexcept>

struct CyberdyneSeries800 {
  CyberdyneSeries800() { printf("I'm a friend of Sarah Conner."); }
  ~CyberdyneSeries800() { throw std::runtime_error{"Second Exception"}; }
};

int main() {
  try {
    CyberdyneSeries800 t800;
    throw std::runtime_error{"First Exception"};
  } catch (const std::exception& e) {
    printf("Caught exception: %s\n", e.what());
  }
}