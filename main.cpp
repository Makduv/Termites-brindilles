// main.cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "coord.h"
#include "grille.h"
#include "termite.h"

using namespace std;

const int NB_TERMITES = 10;
const int NB_BRINDILLES = 50;

void initialiserJeu(Grille &g, vector<Termite> &termites) {
    initialiseGrilleVide(g);
    srand(time(0));

    for (int i = 0; i < NB_BRINDILLES; ++i) {
        Coord c = creeCoord(rand() % TAILLE, rand() % TAILLE);
        while (!estVide(g, c)) c = creeCoord(rand() % TAILLE, rand() % TAILLE);
        poseBrindille(g, c);
    }

    for (int i = 0; i < NB_TERMITES; ++i) {
        Coord c = creeCoord(rand() % TAILLE, rand() % TAILLE);
        while (!estVide(g, c)) c = creeCoord(rand() % TAILLE, rand() % TAILLE);
        Termite t;
        initialiseTermite(t, c, Direction(rand() % 8));
        termites.push_back(t);
        poseTermite(g, c, i);
    }
}

void simulation(Grille &g, vector<Termite> &termites) {
    int nbPasse = 1;
    char cmd;
    do {
        for (int i = 0; i < nbPasse; ++i) {
            for (int j = 0; j < termites.size(); ++j) {
                if (termites[j].porte) {
                    if (termites[j].sablier >= 6 && pasEnferme(termites[j], g) && laVoieEstLibre(termites[j], g)) {
                        dechargeTermite(termites[j], g);
                    } else {
                        marcheAleatoire(termites[j], g);
                    }
                } else {
                    if (brindilleEnFace(termites[j], g)) {
                        chargeTermite(termites[j], g);
                    } else {
                        marcheAleatoire(termites[j], g);
                    }
                }
            }
        }
        afficheGrille(g);
        cout << "Commandes : [Entrer]=continue, '.'=quitter, '*'=x2, '/'=/2 : ";
        cin.get(cmd);
        if (cmd == '*') nbPasse *= 2;
        else if (cmd == '/') nbPasse = max(1, nbPasse / 2);
    } while (cmd != '.');
}

int main() {
    Grille g;
    vector<Termite> termites;
    initialiserJeu(g, termites);
    simulation(g, termites);
    return 0;
}
