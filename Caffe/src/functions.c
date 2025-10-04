#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mystruct.h"


void printBeverage(const Beverage *b)
{
    printf("Id: %d, Nome: %s, price: %d\n", b->id, b->name, b->price);
}

void printBeverageInPrep(const BeverageInPrep *b)
{
    printf("Nome: %s, price: %d\n", b->name, b->price);
}

// ===== Menu =====

// Print the menu
// The first is printed without the index because it's considerd the title
// The last choice is considerd the Exit so it has -1 as its index
void printMenu(const char *menu[], int l)
{
    printf("%s\n", menu[0]);

    for (int i = 1; i < l; i++)
    {
        if (i == l - 1)
            printf("[-1] - %s\n", menu[i]);
        else
            printf("[%d] - %s\n", (i), menu[i]);
    }
}

int menuChoice(int numbersOfC)
{
    printf("                                       Number of choice: %d", numbersOfC);
    int choice = -1;
    int isValid = 0;

    while (!isValid)
    {
        isValid = 1;
        printf("Inserisci la scelta: ");
        scanf("%d", &choice);

        if (choice == -1)
            break;

        if (choice < 1 || choice > numbersOfC)
        {
            printf("Scelta non valida.\n");
            isValid = 0;
        }
    }

    return choice;
}

// Trasform an array of beverage into a menu of strings and add these string on the bottom of the "char *menu[]"
void beverageToMenu(char *menu[], int start, int stop, Beverage *b, int lOfb)
{
    int maxItems = stop - start;
    if (lOfb > maxItems)
    {
        lOfb = maxItems;
    }

    for (int i = 0; i < lOfb; i++)
    {
        // Crea la stringa descrittiva
        char buffer[100];
        snprintf(buffer, sizeof(buffer), "Bevanda: %s - Prezzo: %.2f€ - Acqua: %d%%", b[i].name, b[i].price / 100.0, b[i].water);

        // Alloca spazio e copia nel menu
        menu[start + i] = malloc(strlen(buffer) + 1);
        if (menu[start + i] != NULL)
        {
            strcpy(menu[start + i], buffer);
        }
        else
        {
            fprintf(stderr, "Errore: memoria insufficiente per voce di menu.\n");
        }
    }
}

void progressBar(int time) {
    for (int i = 0; i < time; i++) {
        printf("\rTempo di attesa stimato: %d         ", (time - i));
        fflush(stdout);
        sleep(1);
    }
    
    printf("\rAttesa completata            \n");
}


