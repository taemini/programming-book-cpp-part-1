#include <cstdio>
#include <stdexcept>
#include <utility>

struct SimpleString {
  SimpleString(size_t max_size) : max_size{max_size} {
    if (max_size == 0) {
      throw std::length_error("max_size must be greater than 0");
    }
    buffer = new char[max_size];
    length = 0;
    buffer[0] = '\0';
  }
  ~SimpleString() { delete[] buffer; }

  // copy constructor
  SimpleString(SimpleString& other)
      : length{other.length},
        max_size{other.max_size},
        buffer{new char[max_size]} {
    strncpy(buffer, other.buffer, max_size);
  }
  // copy assignment operator
  SimpleString& operator=(const SimpleString& other) {
    if (this == &other) return *this;
    delete[] buffer;
    max_size = other.max_size;
    length = other.length;
    buffer = new char[other.max_size];
    strncpy(buffer, other.buffer, max_size);
    return *this;
  }

  // move constructor
  SimpleString(SimpleString&& other) noexcept
      : length{other.length}, max_size{other.max_size}, buffer{other.buffer} {
    other.length = 0;
    other.buffer = nullptr;
    other.max_size = 0;
  }
  // move assignment operator
  SimpleString& operator=(SimpleString&& other) noexcept {
    if (this == &other) return *this;
    delete[] buffer;
    max_size = other.max_size;
    length = other.length;
    buffer = other.buffer;
    other.buffer = nullptr;
    other.max_size = 0;
    other.length = 0;
    return *this;
  }

  void print(const char* label) { printf("%s : %s\n", label, buffer); }
  void append_line(const char* x) {
    const auto x_length = strlen(x);
    if (x_length + 2 > max_size) {
      throw std::runtime_error("overflow");
    }
    strncpy(buffer + length, x, x_length);
    length = length + x_length;
    buffer[length++] = '\n';
    buffer[length] = 0;
  }

 private:
  size_t max_size;
  char* buffer;
  size_t length;
};

int main() {
  // try {
  //   SimpleString e{0};
  // } catch (std::exception& e) {
  //   printf("%s\n", e.what());
  // }
  SimpleString a{100};
  a.append_line("hello");
  a.print("a");
  a.append_line("world");
  a.print("a");
  SimpleString b{a};
  b.print("b");
  b.append_line("foo");
  a.print("a");
  b.print("b");
  SimpleString c{3};
  c = b;
  c.print("c");
  SimpleString d{std::move(c)};
  c.print("c");
  d.print("d");

  SimpleString e{3};
  e = std::move(d);
  d.print("d");
  e.print("e");
}