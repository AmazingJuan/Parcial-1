#include <iostream>
#include "Headers/Candado.h"
#include "Headers/Estructuras.h"
using namespace std;

int main()
{
    int** hola = crearMatriz(3);
    int** hola2 = crearMatriz(6);
    int* posiciones = new int[2];
    posiciones[0] = 2;
    posiciones[1] = 1;
    int *resultado = new int[2];
    int* ordenes = new int[2];
    ordenes[0] = 3;
    ordenes[1] = 6;
    int *regla = new int[5];
    regla[0] = 2;
    regla[1] = 1;
    regla[2] = 1;
    regla[3] = 1;
    regla[4] = 0;
    cout << encontrarComb(hola, hola2, regla, resultado, ordenes);
    cout << resultado[0] << resultado[1];
    delete [] resultado;
    delete [] ordenes;
    delete [] posiciones;
}
