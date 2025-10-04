#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystruct.h"

void printBeverage(const Beverage *b) {
  printf("Id: %d, Nome: %s, price: %d\n", b->id, b->name, b->price);
}

void printBeverageInPrep(const BeverageInPrep *b) {
  printf("Nome: %s, price: %d\n", b->name, b->price);
}

void printMenu(const char *menu[], int l) {
  for (int i = 1; i < l; i++) {
    printf("[%d] - %s\n", (i+1), menu[i]);
  }
}

int menuChoice(int numbersOfC) {
  int choice = -1;
  int isValid = 0;

  while (!isValid) {
    isValid = 1;
    printf("Inserisci la scelta: ");
    scanf("%d", &choice);

    if (choice == -1) break;

    if (choice < 1 || choice > numbersOfC) {
      printf("Scelta non valida.\n");
      isValid = 0;
    }
  }

  return choice;
}

// ===== Menu =====
void beverageToMenu(char *menu[], int start, int stop, Beverage *b, int lOfb) {
  int maxItems = stop - start;
  if (lOfb > maxItems) {
    lOfb = maxItems;
  }

  for (int i = 0; i < lOfb; i++) {
    // Crea la stringa descrittiva
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "Bevanda: %s - Prezzo: %.2f€ - Acqua: %d%%", b[i].name, b[i].price / 100.0, b[i].water);

    // Alloca spazio e copia nel menu
    menu[start + i] = malloc(strlen(buffer) + 1);
    if (menu[start + i] != NULL) {
      strcpy(menu[start + i], buffer);
    } else {
      fprintf(stderr, "Errore: memoria insufficiente per voce di menu.\n");
    }
  }
}