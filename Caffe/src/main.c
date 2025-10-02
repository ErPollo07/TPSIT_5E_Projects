#include <stdio.h>
#include "mystruct.h"

int main() {
  Beverage b[] = {
    {1, "Acqua Naturale", 99, 50},
    {2, "Cola", 89, 120},
    {3, "Tè Freddo", 92, 100},
    {4, "Succo d'Arancia", 88, 150},
    {5, "Birra", 93, 200}
  };
  int lOfb = sizeof(b) / sizeof(Beverage);

  const int STATIC_OPTIONS = 2;
  const int TOTAL_MENU = STATIC_OPTIONS + lOfb;

  char **MAIN_MENU = malloc(TOTAL_MENU * sizeof(char *));
  if (!MAIN_MENU) {
    fprintf(stderr, "Errore allocazione menu\n");
    return 1;
  }

  // Aggiunta delle voci statiche
  MAIN_MENU[0] = strdup("===== MAIN MENU =====")
  MAIN_MENU[1] = strdup("Manutenzione: Caricare l'acqua\n");
  MAIN_MENU[1] = strdup("Manutenzione: Svuotare cialde usate\n");

  // Aggiunta delle bevande dinamiche
  beverageToMenu(MAIN_MENU, STATIC_OPTIONS, TOTAL_MENU, b, lOfb);

  // Stampa del menu
  printMenu((const char **)MAIN_MENU, TOTAL_MENU);

  switch (menuChoice(0))
  {
    case 1:
      
      break;
    
    default:
      break;
  }

  // Pulisci memoria
  for (int i = 0; i < TOTAL_MENU; i++) {
    free(MAIN_MENU[i]);
  }
  free(MAIN_MENU);

  printf("\n\n");
  return 0;
}