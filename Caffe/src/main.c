#include <stdio.h>
#include "mystruct.h"

int main() {
  Beverage b = {0, "Caffe", 3};
  printBeverage(&b);

  printf("\n\n");
  return 0;
}