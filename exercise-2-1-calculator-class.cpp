#include <cstdio>

enum class Operation { Add, Subtract, Multiply, Divide };

struct Calculator {
  Calculator(Operation operationArg) { operation = operationArg; }

  int calculate(int a, int b) {
    switch (operation) {
      case Operation::Add:
        return a + b;
      case Operation::Subtract:
        return a - b;
      case Operation::Multiply:
        return a * b;
      case Operation::Divide:
        return a / b;
    }
  }

 private:
  Operation operation;
};

int main() {
  Calculator adder{Operation::Add};
  printf("1 + 2 = %d\n", adder.calculate(1, 2));
  Calculator subtractor{Operation::Subtract};
  printf("1 - 10 = %d\n", subtractor.calculate(1, 10));
  Calculator multiplier{Operation::Multiply};
  printf("8 x 7 = %d\n", multiplier.calculate(8, 7));
  Calculator divider{Operation::Divide};
  printf("7 / 3 = %d\n", divider.calculate(7, 3));
}
