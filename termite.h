// termite.h
#ifndef TERMITE_H
#define TERMITE_H

#include "coord.h"
#include "grille.h"

struct Termite {
    Coord position;
    Direction direction;
    bool porte;
    int sablier;
};

void initialiseTermite(Termite &t, Coord c, Direction d);
Coord devantTermite(const Termite &t);
Direction directionTermite(const Termite &t);
bool porteBrindille(const Termite &t);

void tourneAGauche(Termite &t);
void tourneADroite(Termite &t);
void tourneAleat(Termite &t);

bool laVoieEstLibre(const Termite &t, const Grille &g);
bool brindilleEnFace(const Termite &t, const Grille &g);
bool pasEnferme(const Termite &t, const Grille &g);

void avanceTermite(Termite &t, Grille &g);
void chargeTermite(Termite &t, Grille &g);
void dechargeTermite(Termite &t, Grille &g);
void marcheAleatoire(Termite &t, Grille &g);

#endif
