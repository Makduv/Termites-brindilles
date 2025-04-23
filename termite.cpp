// termite.cpp
#include "termite.h"
#include <cstdlib>

void initialiseTermite(Termite &t, Coord c, Direction d) {
    t.position = c;
    t.direction = d;
    t.porte = false;
    t.sablier = 0;
}

Coord devantTermite(const Termite &t) {
    return devantCoord(t.position, t.direction);
}

Direction directionTermite(const Termite &t) {
    return t.direction;
}

bool porteBrindille(const Termite &t) {
    return t.porte;
}

void tourneAGauche(Termite &t) {
    t.direction = aGauche(t.direction);
}

void tourneADroite(Termite &t) {
    t.direction = aDroite(t.direction);
}

void tourneAleat(Termite &t) {
    int r = rand() % 2;
    if (r == 0) tourneADroite(t);
    else tourneAGauche(t);
}

bool laVoieEstLibre(const Termite &t, const Grille &g) {
    Coord c = devantTermite(t);
    return estVide(g, c);
}

bool brindilleEnFace(const Termite &t, const Grille &g) {
    Coord c = devantTermite(t);
    return contientBrindille(g, c);
}

bool pasEnferme(const Termite &t, const Grille &g) {
    for (int i = 0; i < 8; ++i) {
        Coord c = devantCoord(t.position, Direction(i));
        if (estVide(g, c)) return true;
    }
    return false;
}

void avanceTermite(Termite &t, Grille &g) {
    Coord c = devantTermite(t);
    if (estVide(g, c)) {
        enleveTermite(g, t.position);
        t.position = c;
        poseTermite(g, t.position, numeroTermite(g, t.position));
        t.sablier++;
    }
}

void chargeTermite(Termite &t, Grille &g) {
    Coord c = devantTermite(t);
    if (contientBrindille(g, c)) {
        enleveBrindille(g, c);
        t.porte = true;
        t.sablier = 0;
    }
}

void dechargeTermite(Termite &t, Grille &g) {
    Coord c = devantTermite(t);
    if (estVide(g, c)) {
        poseBrindille(g, c);
        t.porte = false;
        t.sablier = 0;
    }
}

void marcheAleatoire(Termite &t, Grille &g) {
    if (laVoieEstLibre(t, g) && rand() % 10 < 9) {
        avanceTermite(t, g);
    } else {
        tourneAleat(t);
    }
}
