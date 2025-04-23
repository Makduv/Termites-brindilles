// grille.cpp
#include "grille.h"
#include <iostream>
using namespace std;

void initialiseGrilleVide(Grille &g) {
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            g.terrain[i][j].brindille = false;
            g.terrain[i][j].termite = -1;
        }
    }
}

bool dansGrille(Coord c) {
    return c.x >= 0 && c.x < TAILLE && c.y >= 0 && c.y < TAILLE;
}

bool estVide(const Grille &g, Coord c) {
    return dansGrille(c) && !g.terrain[c.x][c.y].brindille && g.terrain[c.x][c.y].termite == -1;
}

bool contientBrindille(const Grille &g, Coord c) {
    return dansGrille(c) && g.terrain[c.x][c.y].brindille;
}

int numeroTermite(const Grille &g, Coord c) {
    return dansGrille(c) ? g.terrain[c.x][c.y].termite : -1;
}

void poseBrindille(Grille &g, Coord c) {
    if (dansGrille(c)) g.terrain[c.x][c.y].brindille = true;
}

void enleveBrindille(Grille &g, Coord c) {
    if (dansGrille(c)) g.terrain[c.x][c.y].brindille = false;
}

void poseTermite(Grille &g, Coord c, int num) {
    if (dansGrille(c)) g.terrain[c.x][c.y].termite = num;
}

void enleveTermite(Grille &g, Coord c) {
    if (dansGrille(c)) g.terrain[c.x][c.y].termite = -1;
}

void afficheGrille(const Grille &g) {
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            if (g.terrain[i][j].termite != -1) cout << 'T';
            else if (g.terrain[i][j].brindille) cout << '*';
            else cout << '.';
        }
        cout << endl;
    }
}
