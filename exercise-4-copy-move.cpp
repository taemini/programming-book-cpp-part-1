#include <chrono>
#include <cstdio>
#include <utility>

struct TimerClass {
  TimerClass(const char* name) : timestamp{} {
    const auto now = std::chrono::system_clock::now();
    timestamp = std::chrono::duration_cast<std::chrono::microseconds>(
                    now.time_since_epoch())
                    .count();
    this->name = new char[10];
    strncpy(this->name, name, 9);
    this->name[9] = 0;
  }
  ~TimerClass() {
    delete[] name;
    const auto now = std::chrono::system_clock::now();
    if (timestamp != 0) {
      auto new_timestamp =
          std::chrono::duration_cast<std::chrono::microseconds>(
              now.time_since_epoch())
              .count();
      printf("Destructed, age of this timer: %lld\n",
             new_timestamp - timestamp);
    }
  }

  void print() { printf("%s : %lld\n", name, timestamp); }

  // copy constructor & copy assignment operator
  TimerClass(const TimerClass& other) : timestamp{} {
    timestamp = other.timestamp;
    name = new char[10];
    strncpy(name, other.name, 10);
  }
  TimerClass& operator=(const TimerClass& other) {
    if (this == &other) return *this;
    timestamp = other.timestamp;
    name = new char[10];
    strncpy(name, other.name, 10);
    return *this;
  }

  // move constructor & move assignment operator
  TimerClass(TimerClass&& other) noexcept : timestamp{} {
    timestamp = other.timestamp;
    name = other.name;
    other.name = nullptr;
    other.timestamp = 0;
  }
  TimerClass& operator=(TimerClass&& other) noexcept {
    if (this == &other) return *this;
    timestamp = other.timestamp;
    name = other.name;
    other.name = nullptr;
    other.timestamp = 0;
    return *this;
  }

 private:
  long long timestamp;
  char* name;
};

int main() {
  TimerClass a{"a"};
  a.print();
  TimerClass b{a};
  b.print();
}
