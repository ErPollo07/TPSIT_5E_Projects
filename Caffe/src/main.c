#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mystruct.h"

#define TRASH_MAX 2
#define WATER_MAX 100
#define WATER_PER_SECONDS 5
#define STATIC_OPTIONS 3

#define PROGRESS_BAR_SPACE 10

#define WATER_HEATER_TIME 10

int main()
{
    int g_trash = 0;
    int g_water = WATER_MAX;
    int g_continue = 1;

    Beverage b[] = {
        {1, "Espresso", 30, 100},
        {2, "Cappuccino", 50, 150},
        {3, "Latte Macchiato", 70, 180},
        {4, "Cioccolata", 60, 200},
        {5, "Tè caldo", 80, 120},
        {6, "Acqua calda", 90, 50}
    };
    int lOfb = sizeof(b) / sizeof(Beverage);

    const int TOTAL_MENU = STATIC_OPTIONS + lOfb + 1;

    char **MAIN_MENU = malloc(TOTAL_MENU * sizeof(char *));
    if (!MAIN_MENU)
    {
        fprintf(stderr, "Errore allocazione menu\n");
        return 1;
    }

    // Aggiunta delle voci statiche
    MAIN_MENU[0] = strdup("===== MAIN MENU =====");
    MAIN_MENU[1] = strdup("Manutenzione: Caricare l'acqua");
    MAIN_MENU[2] = strdup("Manutenzione: Svuotare cialde usate");

    // Aggiunta delle bevande dinamiche
    beverageToMenu(MAIN_MENU, STATIC_OPTIONS, TOTAL_MENU - 1, b, lOfb);

    MAIN_MENU[TOTAL_MENU - 1] = strdup("Exit");

    // Accendo la caldaia
    printf("CALDAIA IN ACCENSIONE\n");

    progressBar(WATER_HEATER_TIME, PROGRESS_BAR_SPACE);

    while (g_continue)
    {
        // Eseguire controlli
        if (g_trash == TRASH_MAX)
        {
            printf("========= WARNING =======\n");
            printf("     SVUOTARE CESTINO\n");
            printf("=========================\n\n");
        }

        printMenu((const char **)MAIN_MENU, TOTAL_MENU);

        int choice = menuChoice(TOTAL_MENU);

        printf("hai scelto: %d\n", choice);

        // switch (choice)
        // {
        // // Caricare l'acqua
        // case 1:
        //     g_water = WATER_MAX;
        //     break;

        // // Svuota cialde usate
        // case 2:
        //     g_trash = 0;
        //     break;

        // // Se ha scelto una bevanda allora parte la preparazione
        // default:
        //     // Se choice e' -1 allora l'utente ha scelto di uscire
        //     if (choice == -1)
        //     {
        //         g_continue = 0;
        //         break;
        //     }

        //     // Rieseguo i controlli
        //     if (g_trash == TRASH_MAX) {
        //         printf("WARNING: SVUOTARE CESTINO\n");
        //         printf("WARNING: OPERAZIONE ANNULATA\n");
        //         break;
        //     }

        //     // Calcolo l'index della bevanda scelta
        //     int idx = choice - STATIC_OPTIONS;

        //     // acqua necessaria
        //     int waterForBeverage = b[idx].water;

        //     // controllo l'acqua
        //     if (g_water == WATER_MAX)
        //     {
        //         printf("WARNING: RIEMPIRE IL SERBATOIO DELL'ACQUA\n");
        //         printf("WARNING: OPERAZIONE ANNULATA\n");
        //         break;
        //     }

        //     // PREPAZIONE
        //     // Calcolo del tempo necessario a erogare l'acqua
        //     int timeForPreparation = (int)(waterForBeverage / WATER_PER_SECONDS);

        //     // visualizzazione della progress bar
        //     progressBar(timeForPreparation, PROGRESS_BAR_SPACE);

        //     printf("LA BEVANDA E' PRONTA\n");

        //     // Incremento della spazzatura
        //     g_trash++;

        //     break;
        // }

        printf("\n\n");
    }

    // Pulisci memoria
    for (int i = 0; i < TOTAL_MENU; i++)
    {
        free(MAIN_MENU[i]);
    }
    free(MAIN_MENU);

    printf("\n\n");
    return 0;
}