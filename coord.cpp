#include <iostream>
using namespace std;

#include "coord.h"
#include <stdexcept>
bool egalCoord(Coord a, Coord b) {
    return (a.x == b.x && a.y == b.y);
}

Coord creeCoord(int lig, int col){
    Coord nouv;
    nouv.x = lig;
    nouv.y = col;
    return nouv;
}

void afficheCoord(Coord x){
    cout << x.x << ", " << x.y << endl;
}

int getX(Coord x){
    return x.x;
}

int getY(Coord x){
    return x.y;
}

void afficheDirection(Direction dir){
    cout << nomDir[dir] << endl;
}

Direction aGauche(Direction d){
    Direction dg;
    if(d == N){
        dg = NO;
    }
    else {
        dg = Direction(d-1);
    }
    return dg;
}

Direction aDroite(Direction d){
    Direction dd;
    if(d == NO){
        dd = N;
    }
    else {
        dd = Direction(d+1);
    }
    return dd;
}

Coord devantCoord(Coord c, Direction dir){
    Coord c1;
    if(dir == NO){
        c1.x = c.x -1;
        c1.y = c.y - 1;
    } else if(dir == N){
        c1.x = c.x;
        c1.y = c.y - 1;
    } else if(dir == NE){
        c1.x = c.x + 1;
        c1.y = c.y - 1;
    } else if(dir == O){
        c1.x = c.x - 1;
        c1.y = c.y;
    } else if(dir == E){
        c1.x = c.x + 1;
        c1.y = c.y;
    }else if(dir == SO){
        c1.x = c.x -1;
        c1.y = c.y + 1;
    } else if(dir == S){
        c1.x = c.x;
        c1.y = c.y + 1;
    } else {
        c1.x = c.x + 1;
        c1.y = c.y + 1;
    }
    return c1;
}
