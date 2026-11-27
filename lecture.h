#ifndef LECTEUR_H
#define LECTEUR_H

#include <stdio.h>
#include <stdint.h>


typedef struct {
    uint16_t annee;
    uint32_t id_collision;
    char id_vehicule[4];
    uint8_t place;
    uint8_t type_usager;
    uint8_t gravite;
    uint8_t genre;
    uint16_t annee_naissance;
    int8_t trajet;
} Enregistrement;

FILE *ouvrir_fichier(const char *chemin);
int lire_enregistrement(FILE *fichier, Enregistrement *e);
void quitter_erreur(const char *message);

#endif


