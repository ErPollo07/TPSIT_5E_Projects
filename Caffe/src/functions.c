#include <stdio.h>
#include "mystruct.h"

void printBeverage(const Beverage *b) {
  printf("Id: %d, Nome: %s, price: %d\n", b->id, b->name, b->price);
}