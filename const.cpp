#include <cstdio>

struct ClockOfTheLongNow {
  ClockOfTheLongNow(long year) : year{year} {}
  void add_year() { year++; }
  bool set_year(int new_year) {
    if (new_year < 2019) return false;
    year = new_year;
    return true;
  }
  long get_year() { return year; }

 private:
  long year;
};
struct Avout {
  Avout(const char* name, long year_of_apert)
      : name{name}, apert{year_of_apert} {}
  void announce() {
    printf("My name is %s and my next apert is %ld.\n", name, apert.get_year());
  }

 private:
  const char* name;
  ClockOfTheLongNow apert;
};

int main() {
  Avout raz{"Eramas", 3010};
  raz.announce();
}