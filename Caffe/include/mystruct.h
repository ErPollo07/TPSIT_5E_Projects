#ifndef MYSTRUCT_H
#define MYSTRUCT_H

typedef struct {
    int id;
    char name[30];
    int price;
} Beverage;

void printBeverage(const Beverage *b);

#endif