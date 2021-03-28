#include <cstdio>
#include <utility>

template <typename T>
struct SimpleUniquePointer {
  SimpleUniquePointer() : pointer{} {}
  SimpleUniquePointer(T* pointer) : pointer{pointer} {}
  ~SimpleUniquePointer() { delete pointer; }
  SimpleUniquePointer(const SimpleUniquePointer&) = delete;
  SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete;
  SimpleUniquePointer(SimpleUniquePointer&& other) noexcept
      : pointer{other.pointer} {
    other.pointer = nullptr;
  }
  SimpleUniquePointer& operator=(SimpleUniquePointer&& other) noexcept {
    pointer = other.pointer;
    other.pointer = nullptr;
    return *this;
  }
  T* get() { return pointer; }

 private:
  T* pointer;
};

struct Tracer {
  Tracer(const char* name, const char* name2) : name{name}, name2{name2} {
    printf("%s %s constructed.\n", name, name2);
  }
  ~Tracer() { printf("%s destructed.\n", name); }

 private:
  const char* const name;
  const char* const name2;
};

void consumer(SimpleUniquePointer<Tracer>&& consumer_ptr) {
  printf("(cons) consumer_ptr: %p\n", consumer_ptr.get());
}

template <typename T, typename... Arguments>
SimpleUniquePointer<T> make_simple_unique(Arguments... arguments) {
  return SimpleUniquePointer<T>{new T{arguments...}};
}

int main() {
  auto ptr_a = SimpleUniquePointer{new Tracer{"ptr_a", "2"}};
  printf("(main) ptr_a: %p\n", ptr_a.get());
  consumer(std::move(ptr_a));
  printf("(main) ptr_a: %p\n", ptr_a.get());

  auto ptr_v_t = make_simple_unique<Tracer>("ptr_v_t", "2");
}