#include <iostream>
#include "Headers/Candado.h"
#include "Headers/Estructuras.h"
using namespace std;

int main()
{
    int *regla = new int[7];
    regla[0] = 4;
    regla[1] = 1;
    regla[2] = -1;
    regla[3] = 1;
    regla[4] = -1;
    regla[5] = -1;
    regla[6] = -1;
    int **resultado = generarCandado(regla, 7);

    for(int contador = 0; contador < 7 - 1; contador++){
        cout << "Orden: " << resultado[contador][0] << endl << "Estado: " << resultado[contador][1] << endl << endl;
    }

}
