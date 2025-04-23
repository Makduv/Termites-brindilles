#include <iostream>
using namespace std;

#include "coord.h"
#include <stdexcept>

#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << endl

void testEgalCoord(){
    ASSERT(egalCoord(creeCoord(1,2),creeCoord(1,2)));
}

void testDevantCoord(){
    ASSERT(egalCoord(devantCoord(creeCoord(1,2), N), creeCoord(1,1)));
}


int main(){
    cout << "Tests de la fonction egalCoord et de la fonction devantCoord" << endl;
    testEgalCoord();
    testDevantCoord();
    return 0;
}
