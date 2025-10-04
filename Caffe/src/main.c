#include <stdio.h>
#include <stdlib.h>
#include "mystruct.h"

#define TRASH_MAX 2
#define WATER_MAX 100
#define STATIC_OPTIONS 3

int main() {
  int g_trash = 2;
  int g_water = WATER_MAX;
  int g_continue = 1;

  Beverage b[] = {
    {1, "Espresso",        30, 100},
    {2, "Cappuccino",      50, 150},
    {3, "Latte Macchiato", 70, 180},
    {4, "Cioccolata",      60, 200},
    {5, "Tè caldo",        80, 120},
    {6, "Acqua calda",     90,  50} 
  };
  int lOfb = sizeof(b) / sizeof(Beverage);

  const int TOTAL_MENU = STATIC_OPTIONS + lOfb;

  char **MAIN_MENU = malloc(TOTAL_MENU * sizeof(char *));
  if (!MAIN_MENU) {
    fprintf(stderr, "Errore allocazione menu\n");
    return 1;
  }

  // Aggiunta delle voci statiche
  MAIN_MENU[0] = strdup("===== MAIN MENU =====");
  MAIN_MENU[1] = strdup("Manutenzione: Caricare l'acqua");
  MAIN_MENU[2] = strdup("Manutenzione: Svuotare cialde usate");

  // Aggiunta delle bevande dinamiche
  beverageToMenu(MAIN_MENU, STATIC_OPTIONS, TOTAL_MENU, b, lOfb);
  
  while (g_continue) {
    // Eseguire controlli
    if (g_trash == TRASH_MAX) {
      printf("WARNING: SVUOTARE CESTINO\n");
    }

    printMenu((const char **)MAIN_MENU, TOTAL_MENU);

    switch (menuChoice(0))
    {
      // Caricare l'acqua
      case 1:
        g_water = WATER_MAX;
        break;
      
      // Svuota cialde usate
      case 2:
        g_trash = 0;
        break;
        
      // Espresso
      case 3:
        int waterForBeverage = b[0].water;

        break;
        
      // Cappuccino
      case 4:
        break;
        
      case 5:
        break;
        
      case 6:
        break;
        
      case 7:
        break;
        
      case 8:
        break;
        
      case 9:
        break;
        
      case 10:
        break;

      default:
        g_continue = 0;
        break;
    }
  }
  

  // Pulisci memoria
  for (int i = 0; i < TOTAL_MENU; i++) {
    free(MAIN_MENU[i]);
  }
  free(MAIN_MENU);

  printf("\n\n");
  return 0;
}