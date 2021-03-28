#include <cstdio>
#include <cstdint>
#include <stdexcept>

template<typename T>
T max(T a, T b) {
  return a > b ? a : b;
} 

struct UnsignedBigInteger {
  const static size_t MAX_SIZE = 5;
  UnsignedBigInteger(const uint8_t* value, size_t length): size{length} {
    if (length > MAX_SIZE) {
      throw std::overflow_error("Too big to save");
    }
    for (size_t i=0; i<length; i++) {
      this->value[i] = value[i];
    }
  }
  void print() const {
    for (size_t i=0; i<size; i++) {
      printf("%d", value[size - i - 1]);
    }
    printf("\n");
  }
  uint8_t get(size_t pos) const {
    return value[pos];
  }
  uint8_t get_size() const {
    return size;
  }
  UnsignedBigInteger operator+(const UnsignedBigInteger other) {
    uint8_t result[MAX_SIZE]{};
    size_t bigger_size = max<size_t>(size, other.get_size());
    size_t size{};
    uint8_t remainer = 0;
    size_t i = 0;
    for (; i < bigger_size; i++) {
      remainer = value[i] + other.get(i) + remainer;
      printf("remainer: %d\n", remainer);
      result[i] = remainer;
      size++;
      if (result[i] >= 10) {
        result[i] -= 10;
        remainer = 1;
      } else {
        remainer = 0;
      }
    }
    if (remainer > 0) {
      if (i >= MAX_SIZE) {
        throw std::overflow_error("Too big to save");
      }
      result[i] = remainer;
      size++;
    }
    return UnsignedBigInteger{ result, size };
  }
  
  private:
    uint8_t value[MAX_SIZE]{};
    size_t size;
};

int main() {
  printf("Exercise 7-1 UnsignedBigInteger\n");
  uint8_t arg[4]{6,5,4,8}; // 1234
  UnsignedBigInteger a{ arg, 4 };
  UnsignedBigInteger b{ arg, 4 };
  UnsignedBigInteger c= a + b;
  a.print();
  c.print();
};