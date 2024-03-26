#include <iostream>
#include "Headers/Candado.h"
#include "Headers/Estructuras.h"
using namespace std;

int main()
{
    int *regla = new int[5];
    regla[0] = 4;
    regla[1] = 3;
    regla[2] = 1;
    regla[3] = -1;
    regla[4] = 1;
    int **resultado = generarCandado(regla, 5);

    for(int cont = 0; cont < 5 - 1; cont++){
        cout << "Orden: " << resultado[cont][0] << endl << "Estado: " << resultado[cont][1] << endl << endl;
    }

}
