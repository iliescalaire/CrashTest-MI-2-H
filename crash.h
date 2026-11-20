
#ifndef CRASH_H
#define CRASH_H

#include <stdint.h>
#include "lecteur.h"

typedef struct NoeudAccident NoeudAccident;

uint64_t creer_cle(uint16_t annee, uint32_t id_collision);
NoeudAccident *accident_inserer(NoeudAccident *racine, const Enregistrement *e);
NoeudAccident *accident_chercher(NoeudAccident *racine, uint64_t cle);
void accident_afficher(const NoeudAccident *noeud);
void accident_liberer(NoeudAccident *racine);
void lancer_accident(const char *chemin);

#endif



