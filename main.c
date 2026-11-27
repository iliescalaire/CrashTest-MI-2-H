#include <stdio.h>
#include <string.h>
#include "lecteur.h"
#include "annee.h"

int main(int argc, char *argv[])
{

    if (argc != 3) {
        quitter_erreur("usage : ./crashTech MODE fichier.csv");
    }

    if (strcmp(argv[1], "YEAR_DATA") == 0) {
        lancer_annee(argv[2]);
    } else if (strcmp(argv[1], "AGE_DATA") == 0
               || strcmp(argv[1], "CRASH_DATA") == 0) {
        quitter_erreur("ce mode n'est pas encore disponible");
    } else {
        quitter_erreur("mode inconnu (YEAR_DATA, AGE_DATA ou CRASH_DATA)");
    }
    return 0;
}
