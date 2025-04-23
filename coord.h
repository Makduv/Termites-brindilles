#ifndef PROJET_S2_COORD_H
#define PROJET_S2_COORD_H

enum Direction{N, NE, E, SE, S, SO, O, NO};
const string nomDir[8] = {"Nord", "Nord-Est", "Est", "Sud-Est", "Sud", "Sud-Ouest", "Ouest", "Nord-Ouest"};

struct Coord{
    int x, y;
};

/** Construire une image en teintes de gris depuis un fichier PGM
 * @param lig
 * @param col
 * @return une nouvelle coordonnee
 **/
Coord creeCoord(int lig, int col);

void afficheCoord(Coord x);

int getX(Coord x);

int getY(Coord x);

bool egalCoord(Coord a, Coord b);

void afficheDirection(Direction dir);

Direction aGauche(Direction d);

Direction aDroite(Direction d);

Coord devantCoord(Coord c, Direction dir);

#endif //PROJET_S2_COORD_H
