#import "../Headers/Utilidades.h"

int genRandom(int menor, int mayor){ //fue sacada de interne
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.
    uniform_int_distribution<> dist(menor, mayor); // distribute results between 1 and 6 inclusive.
    return dist(gen);
}
