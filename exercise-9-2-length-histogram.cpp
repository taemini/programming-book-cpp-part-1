#include <cstdio>

constexpr size_t max_size = 10;

struct LengthHistogram {
  void ingest(const char* str);
  void print();
  private:
    size_t char_lengths[max_size]{};
    size_t pos{};
};

void LengthHistogram::ingest(const char* str) {
  size_t index{};
  while(str[index]) index++;
  char_lengths[pos++] = index;
}

void LengthHistogram::print() {
  for(size_t i{}; i<max_size; i++) {
    printf("[%zu]: ", i);
    auto n_asterisks = char_lengths[i];
    while(n_asterisks--) {
      printf("*");
    }
    printf("\n");
  }
}

int main(int argc, char** argv) {
  LengthHistogram histo{};
  for(size_t index{1}; index<argc; index++) {
    histo.ingest(argv[index]);
  }
  histo.print();
}