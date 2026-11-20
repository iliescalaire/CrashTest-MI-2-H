#ifndef AGE_H
#define AGE_H

#include "lecteur.h"

typedef struct MaillonAge MaillonAge;

void age_ajouter(MaillonAge **tete, const Enregistrement *e);
void age_afficher(const MaillonAge *tete, int mode, int filtre_type, int filtre_genre);
void age_liberer(MaillonAge *tete);
void lancer_age(const char *chemin);

#endif
