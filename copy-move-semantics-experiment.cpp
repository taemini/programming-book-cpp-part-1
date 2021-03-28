// 이 코드는 copy semantics이기 때문에 double free가 일어날 위험이 있음

#include <cstdio>
#include <cstring>
#include <stdexcept>

// resource acquisition is initialization (RAII) pattern
// OR constructor acquires, destructor releases (CADRe) pattern
struct SimpleString {
  SimpleString(size_t max_size) : max_size{max_size}, length{} {
    if (max_size == 0) {
      throw std::runtime_error{"Max size must be at least 1."};
    }
    buffer = new char[max_size];
    buffer[0] = 0;
  }
  // copy constructor
  SimpleString(const SimpleString& other)
      : max_size{other.max_size},
        buffer{new char[other.max_size]},
        length{other.length} {
    std::strncpy(buffer, other.buffer, max_size);
  }
  // move constructor
  SimpleString(SimpleString&& other) noexcept
      : max_size{other.max_size}, buffer(other.buffer), length(other.length) {
    other.length = 0, other.buffer = nullptr;
    other.max_size = 0;
  }

  // copy assignment operator
  SimpleString& operator=(const SimpleString& other) {
    if (this == &other) return *this;
    const auto new_buffer = new char[other.max_size];
    delete[] buffer;
    buffer = new_buffer;
    length = other.length;
    max_size = other.max_size;
    strncpy(buffer, other.buffer, max_size);
    return *this;
  }
  // move assignment operator
  SimpleString& operator=(SimpleString&& other) noexcept {
    if (this == &other) return *this;
    delete[] buffer;
    buffer = other.buffer;
    length = other.length;
    max_size = other.max_size;
    other.buffer = nullptr;
    other.length = 0;
    other.max_size = 0;
    return *this;
  }

  ~SimpleString() { delete[] buffer; }

  void print(const char* tag) const { printf("%s: %s", tag, buffer); }

  bool append_line(const char* x) {
    const auto x_len = strlen(x);
    if (x_len + length + 2 > max_size) return false;
    std::strncpy(buffer + length, x, max_size - length);
    length += x_len;
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
  }

 private:
  size_t max_size;
  char* buffer;
  size_t length;
};

// call by value (which invokes copy constructor)
void foo(SimpleString x) { x.append_line("Change lost."); }

// call by reference
// void foo(SimpleString& x) { x.append_line("Change preserved."); }

int main() {
  SimpleString a{50};
  a.append_line("We apologize for the");
  SimpleString a_copy{a};
  a.append_line("inconvenience.");
  a_copy.append_line("incontinece.");
  a.print("a");
  a_copy.print("a_copy");
  printf("---------------------\n");

  SimpleString b{20};
  foo(b);
  b.print("Still empty");
  printf("\n---------------------\n");

  SimpleString c{50};
  c.append_line("We apologize for the");
  SimpleString d{50};
  d.append_line("Last message");
  c.print("c");
  d.print("d");
  d = c;
  c.print("c");
  d.print("d");
  printf("----------------------\n");

  SimpleString e{50};
  e.append_line("We apologize for the");
  SimpleString f{50};
  f.append_line("Last message");
  e.print("e");
  f.print("f");
  f = std::move(e);  // invokes "move assignment operator"
  // a is "moved-from"
  f.print("f");
  e.print("e");
}