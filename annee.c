#include <stdio.h>
#include <stdlib.h>
#include "annee.h"

#define ANNEE_MIN 2005
#define ANNEE_MAX 2024
#define NB_ANNEES (ANNEE_MAX - ANNEE_MIN + 1)
#define NB_GRAVITES 4


typedef struct {
    uint32_t nb_accidents;
    uint32_t gravite[NB_GRAVITES];  
} StatsAnnee;


static StatsAnnee stats[NB_ANNEES];

static uint16_t derniere_annee = 0;
static uint32_t dernier_id = 0;

void annee_ajouter(const Enregistrement *e)
{
    StatsAnnee *s;

    if (e->annee < ANNEE_MIN || e->annee > ANNEE_MAX) {
        quitter_erreur("annee hors de la plage 2005-2024");
    }
    if (e->gravite < 1 || e->gravite > NB_GRAVITES) {
        quitter_erreur("gravite invalide dans le fichier");
    }
    s = &stats[e->annee - ANNEE_MIN];

   
    if (e->annee != derniere_annee || e->id_collision != dernier_id) {
        s->nb_accidents++;
        derniere_annee = e->annee;
        dernier_id = e->id_collision;
    }
    s->gravite[e->gravite - 1]++;
}


void annee_afficher(int annee)
{
    const StatsAnnee *s;

    if (annee < ANNEE_MIN || annee > ANNEE_MAX) {
        printf("Annee invalide : choisissez entre %d et %d.\n",
               ANNEE_MIN, ANNEE_MAX);
        return;
    }
    s = &stats[annee - ANNEE_MIN];

    printf("\n===== Statistiques %d =====\n", annee);
    printf("Accidents    : %lu\n", (unsigned long)s->nb_accidents);
    printf("Indemnes     : %lu\n", (unsigned long)s->gravite[0]);
    printf("Tues         : %lu\n", (unsigned long)s->gravite[1]);
    printf("Blesses graves : %lu\n", (unsigned long)s->gravite[2]);
    printf("Blesses legers : %lu\n", (unsigned long)s->gravite[3]);
}


static int demander_annee(void)
{
    char saisie[32];
    int valeur;

    printf("\nAnnee a consulter (%d-%d, 0 pour quitter) : ",
           ANNEE_MIN, ANNEE_MAX);
    if (fgets(saisie, sizeof(saisie), stdin) == NULL) {
        return 0;
    }
    if (sscanf(saisie, "%d", &valeur) != 1) {
        return -1;
    }
    return valeur;
}


static void menu_annee(void)
{
    int choix;

    do {
        choix = demander_annee();
        if (choix == -1) {
            printf("Saisie invalide : entrez un nombre.\n");
        } else if (choix != 0) {
            annee_afficher(choix);
        }
    } while (choix != 0);
}


void lancer_annee(const char *chemin)
{
    FILE *fichier = ouvrir_fichier(chemin);
    Enregistrement e;

    while (lire_enregistrement(fichier, &e)) {
        annee_ajouter(&e);
    }
    fclose(fichier);
    menu_annee();
}
