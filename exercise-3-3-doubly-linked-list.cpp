#include <cstdio>

struct Element {
  Element* prev{};
  Element* next{};
  void insert_after(Element* new_element) {
    new_element->prev = this;
    new_element->next = next;
    if (next) {
      next->prev = new_element;
    }
    next = new_element;
  }
  void insert_before(Element* new_element) {
    new_element->prev = prev;
    new_element->next = this;
    if (prev) {
      prev->next = new_element;
    }
    prev = new_element;
  }
  char prefix[2];
  short operating_number;
};

int main() {
  Element trooper1, trooper2, trooper3, trooper4;
  trooper1.prefix[0] = 'T';
  trooper1.prefix[1] = 'K';
  trooper1.operating_number = 111;
  trooper1.insert_after(&trooper2);
  trooper2.prefix[0] = 'F';
  trooper2.prefix[1] = 'N';
  trooper2.operating_number = 222;
  trooper2.insert_after(&trooper3);
  trooper3.prefix[0] = 'T';
  trooper3.prefix[1] = 'M';
  trooper3.operating_number = 333;
  trooper3.insert_after(&trooper4);
  trooper4.prefix[0] = 'L';
  trooper4.prefix[1] = 'S';
  trooper4.operating_number = 444;
  // ASCENDING
  for (Element* cursor = &trooper1; cursor; cursor = cursor->next) {
    printf("stormtrooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1],
           cursor->operating_number);
  }
  printf("\n");
  // DESCENDING
  for (Element* cursor = &trooper4; cursor; cursor = cursor->prev) {
    printf("stormtrooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1],
           cursor->operating_number);
  }
}
