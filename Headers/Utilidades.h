#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "random"
using namespace std;
int genRandom(int menor, int mayor){
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.
    uniform_int_distribution<> dist(menor, mayor); // distribute results between 1 and 6 inclusive.
    return dist(gen);
}

#endif // UTILIDADES_H
