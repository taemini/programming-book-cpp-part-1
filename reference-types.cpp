#include <cstdio>

int main() {
  int* my_ptr;
  printf("The value of my_ptr is %p.\n", my_ptr);

  char lower[] = "abc?e";
  char upper[] = "ABC?E";

  *(lower + 3) = 'd';
  *(upper + 3) = 'D';

  char letter_d = *(lower + 3);
  char letter_D = *(upper + 3);

  printf("%c\n", letter_d);
  printf("%c\n", letter_D);
  printf("%s\n", lower);
  printf("%s\n", upper);

  printf("%p\n", nullptr);
}