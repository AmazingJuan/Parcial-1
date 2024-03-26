#include "../Headers/Candado.h"

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

int *primeraComb(int **matrizUno, int **matrizDos, int *resultado){

}
