#ifndef MYSTRUCT_H
#define MYSTRUCT_H


typedef struct {
  int id;
  char name[30];
  int water;
  int price;
} Beverage;

void printBeverage(const Beverage *b);

typedef struct {
  char name[30];
  double water;
  int sugar;
  int price;
} BeverageInPrep;

void printBeverageInPrep(const BeverageInPrep *b);

void printMenu(const char *menu[], int l);

int menuChoice(int numbersOfC);

void beverageToMenu(char *menu[], int start, int stop, Beverage *b, int lOfb);

#endif