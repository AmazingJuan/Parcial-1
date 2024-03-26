#include <iostream>
#include "Headers/Estructuras.h"
using namespace std;

int main()
{
    int** hola = crearMatriz(5);
    int* posiciones = new int[2];
    posiciones[0] = 0;
    posiciones[1] = 4;
    cout << obtenerRotacion(posiciones, hola, 5, 1);

}
