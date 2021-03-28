#include <cstdio>

struct BaseClass {
  virtual ~BaseClass() = default;
};

struct DerivedClass : BaseClass {
  DerivedClass() { printf("DerivedClass() invoked\n"); }
  ~DerivedClass() { printf("~DerivedClass() invoked\n"); }
};

int main() {
  BaseClass* x{new DerivedClass};
  delete x;
}