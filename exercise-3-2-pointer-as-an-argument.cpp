#include <cstdio>

char read_from(char* string, size_t n_string, size_t index) {
  if (index >= n_string) {
    printf("Buffer overflow!\n");
    return '\0';
  }

  return string[index];
}

bool write_to(char* string, size_t n_string, size_t index, char new_char) {
  if (index >= n_string) {
    printf("Buffer overflow!\n");
    return false;
  }

  string[index] = new_char;
  return true;
}

int main() {
  char lower[] = "abc?e";
  char upper[] = "ABC?E";
  char* upper_ptr = &upper[0];

  *(lower + 3) = 'd';
  *(upper_ptr + 3) = 'D';

  char letter_d = *(lower + 4);  // lower decays into a pointer when we add
  char letter_D = *(upper_ptr + 4);

  printf("lower: %s\nupper: %s\n", lower, upper);

  // *(lower + 7) = 'g'; // Super bad. You must never do this.

  write_to(lower, sizeof(lower) / sizeof(char), 3, 'z');
  printf("%c", read_from(lower, sizeof(lower) / sizeof(char), 3));
}
