#ifndef MYSTRUCT_H
#define MYSTRUCT_H

typedef struct {
  const int TRASH_MAX = 2;
  const int WATER_MAX = 100;
} RuntimeApp;


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


void printMenu(const char *menu[]);

int menuChoice(int numbersOfC);

void beverageToMenu(const *menu[], int start, int stop, Beverage *b, int lOfb);

#endif