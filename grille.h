// grille.h
#ifndef GRILLE_H
#define GRILLE_H

#include "coord.h"

const int TAILLE = 20;

struct Case {
    bool brindille;
    int termite; // -1 s'il n'y a pas de termite
};

struct Grille {
    Case terrain[TAILLE][TAILLE];
};

void initialiseGrilleVide(Grille &g);
bool estVide(const Grille &g, Coord c);
bool dansGrille(Coord c);
bool contientBrindille(const Grille &g, Coord c);
int numeroTermite(const Grille &g, Coord c);

void poseBrindille(Grille &g, Coord c);
void enleveBrindille(Grille &g, Coord c);
void poseTermite(Grille &g, Coord c, int num);
void enleveTermite(Grille &g, Coord c);
void afficheGrille(const Grille &g);

#endif
