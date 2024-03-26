#include "../Headers/Candado.h"
#include "../Headers/Estructuras.h"

bool validarRegla(int *regla, int sizeRegla){
    if(regla[0] <= 0 && regla[1] <= 0) return false;
    if(sizeRegla <= 2) return false;
    for(int cont = 2; cont < sizeRegla; cont++){
        if(regla[cont] != 0 && regla[cont] != -1 && regla[cont] != 1) return false;
    }
    return true;
}


int **generarCandado(int *regla, int sizeRegla){
    int ordenMin;
    int **resultado = new int*[sizeRegla - 1];
    if(regla[0] >= regla[1]) ordenMin = regla[0];
    else ordenMin = regla[1];
}

bool encontrarComb(int **matrizUno, int **matrizDos, int *regla, int*arreglo, int* ordenes){
    int celdaUno = matrizUno[regla[0]][regla[1]];
    int celdaDos = matrizDos[regla[0]][regla[1]];
    bool isEstaticaUno = regla[3];
    bool isEstaticaDos = regla[4];
    int criterio = regla[2];
    int *celda = new int[2];
    int estadoUno = 0;
    int estadoDos = 0;
    celda[0] = regla[0];
    celda[1] = regla[1];

    for(int cont = 0; cont < 4; cont++){
        if(!isEstaticaUno) {
            celdaUno = obtenerRotacion(celda, matrizUno, ordenes[0], cont);
            estadoUno++;
        }
        else cont = 3;
        for(int cont2 = 0; cont2 < 4; cont2++){
            if(!isEstaticaDos){
                celdaDos = obtenerRotacion(celda, matrizDos, ordenes[0], cont2);
                estadoDos++;
            }
           else cont2 = 3;

           if(criterio == -1 && celdaUno < celdaDos){
               arreglo[0] = estadoUno;
               arreglo[1] = estadoDos;
               delete [] celda;
               return true;
           }
           else if(criterio == 1 && celdaUno > celdaDos){
               arreglo[0] = estadoUno;
               arreglo[1] = estadoDos;
               delete [] celda;
               return true;
           }
           else if(criterio == 0 && celdaUno == celdaDos){
               arreglo[0] = estadoUno;
               arreglo[1] = estadoDos;
               delete [] celda;
               return true;
           }
        }
    }
    delete [] celda;
    return false;
}
