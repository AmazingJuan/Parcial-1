#include <iostream>
#include "Headers/Estructuras.h"
using namespace std;

int main()
{
    int *ordenes = new int[2];
    ordenes[0] = 5;
    ordenes[1] = 3;
    int ***Estructura = crearEstructura(ordenes, 2);
    cout << Estructura[0][2][2];
}
