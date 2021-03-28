#include <cstddef>
#include <cstdio>
#include <iterator>

struct Taxonomist {
  Taxonomist() { printf("(no argument)\n"); }
  Taxonomist(char x) { printf("char: %c\n", x); }
  Taxonomist(int x) { printf("int: %d\n", x); }
  Taxonomist(float x) { printf("float: %f\n", x); }
};

int main() {
  unsigned short a = 0b101101;
  printf("%hu\n", a);
  wchar_t w = 'a';
  printf("%zu\n", sizeof(w));
  printf("%zu\n", sizeof(size_t));

  unsigned long maximum = 0;
  unsigned long values[] = {10, 50, 20, 40, 0};

  long double eulers_number = 2.7182818284;
  printf("%Lg\n", eulers_number);

  // for loop
  for (size_t i = 0; i < 5; i++) {
    if (values[i] > maximum) maximum = values[i];
  }
  printf("The maximum value is %lu\n", maximum);

  // range-based for loop
  for (unsigned long value : values) {
    if (value > maximum) maximum = value;
  }
  printf("The maximum value is %lu\n", maximum);

  short array[] = {104, 105, 32, 105};
  printf("The array length is %zu\n", sizeof(array) / sizeof(short));
  printf("The array length is %zu\n", std::size(array));

  char english[] = "A book holds a house of gold.";
  char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";
  printf("A book holds a house of gold.\n");
  printf("\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b\n");
  printf("\U0001F37A\n");
  char concatenated[] =
      "A "
      "book"
      " holds"
      " a house "
      "of gold.";
  printf("%s\n", concatenated);

  enum class Race { Dinan, Teklan, Ivyn, Moiran, Camite, Julian, Aidan };
  Race race = Race::Dinan;
  switch (race) {
    case Race::Dinan: {
      printf("You work hard");
    } break;
    case Race::Aidan: {
      printf("What a enigma");
    } break;
    default: {
      printf("I don't know you");
    }
  }

  struct Book {
    char name[256];
    int year;
    int pages;
    bool hardcover;
  };
  Book neuromancer;
  neuromancer.pages = 256;

  union Variant {
    char string[10];
    int integer;
    double floating_point;
  };
  Variant v;
  v.integer = 42;
  printf("The ultimate answer: %d\n", v.integer);
  v.floating_point = 2.7182818284;
  printf("Euler's number e:  %f\n", v.floating_point);
  printf("A dumpster fire: %d\n", v.integer);

  struct ClockOfTheLongNow {
   public:
    void add_year() { year++; }
    bool set_year(int new_year) {
      if (new_year < 2019) return false;
      year = new_year;
      return true;
    }
    int get_year() { return year; }

   private:
    int year;
  };
  ClockOfTheLongNow clock;
  clock.set_year(2020);
  clock.add_year();
  printf("year: %d\n", clock.get_year());

  Taxonomist t1;
  Taxonomist t2{'c'};
  Taxonomist t3{65537};
  Taxonomist t4{3.7f};

  float num1{1};
  float num2{2};
  int c{num1 /
        num2};  // compiler will warn you that narrowing conversion will occur
  int d = num1 / num2;

  struct JohanVanDerSmut {
    bool gold = true;
    int year_of_smelting_accident{1970};
    char key_location[8] = {"x-rated"};
  };
}