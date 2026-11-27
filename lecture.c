#include <stdio.h>
#include <stdlib.h>
#include "lecteur.h"

#define TAILLE_LIGNE 256

void quitter_erreur(const char *message)
{
    fprintf(stderr, "Erreur : %s\n", message);
    exit(1);
}

FILE *ouvrir_fichier(const char *chemin)
{
    char ligne[TAILLE_LIGNE];
    FILE *fichier = fopen(chemin, "r");

    if (fichier == NULL) {
        quitter_erreur("impossible d'ouvrir le fichier de donnees");
    }
    if (fgets(ligne, TAILLE_LIGNE, fichier) == NULL) {
        quitter_erreur("le fichier est vide");
    }
    return fichier;
}

int lire_enregistrement(FILE *fichier, Enregistrement *e)
{
    char ligne[TAILLE_LIGNE];
    int nb_valeurs;
    do {
        if (fgets(ligne, TAILLE_LIGNE, fichier) == NULL) {
            return 0;
        }
    } while (ligne[0] == '\n' || ligne[0] == '\r');


    nb_valeurs = sscanf(ligne, "%hu;%u;%3[^;];%hhu;%hhu;%hhu;%hhu;%hu;%hhd",
                        &e->annee, &e->id_collision, e->id_vehicule,
                        &e->place, &e->type_usager, &e->gravite,
                        &e->genre, &e->annee_naissance, &e->trajet);

    if (nb_valeurs != 9) {
        quitter_erreur("ligne du fichier mal formee");
    }
    return 1;
}
