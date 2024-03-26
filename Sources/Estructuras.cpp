#include "../Headers/Estructuras.h"

int** crearMatriz(int orden){
    int medio = (orden / 2);
    int contAux = 1;
    int **matriz = new int*[orden];
    for(int fila = 0; fila < orden; fila++){
        matriz[fila] = new int[orden];
        for(int columna = 0; columna < orden; columna++){
            if(fila == medio & columna == medio){
                matriz[fila][columna] = -1;
            }
            else{
                matriz[fila][columna] = contAux;
                contAux++;
            }
        }
    }
    return matriz;
}

int ***crearEstructura(int *ordenes, int numMatrices){
    int ***estructuraPtr = new int**[numMatrices];
    for(int cont = 0; cont < numMatrices; cont++){
        estructuraPtr[cont] = crearMatriz(ordenes[cont]);
    }
    return estructuraPtr;
}

int obtenerRotacion(int *posActual, int **matriz, int orden, int estado){
    int medio = orden / 2;
    int fila = posActual[0];
    int filaAux = fila;
    int columna = posActual[1];
    fila = columna;
    columna = 2*medio - filaAux;

    if(estado == 1) return matriz[fila][columna];
    else if(estado == 2){
        filaAux = fila;
        fila = columna;
        columna = 2*medio - filaAux;
        return matriz[fila][columna];
    }
    else if(estado == 3){
        filaAux = fila;
        fila = columna;
        columna = 2*medio - filaAux;
        return matriz[fila][columna];
    }
    else return matriz[posActual[0]][posActual[1]];
}

int *generarOrdenes(int orden, int tamano){
    int *ordenes = new int[tamano];
    for(int cont = 0; cont < tamano; cont++) ordenes[cont] = orden;
    return ordenes;
}

void editarEstructura(int indice, int ordenNueva, int ***estructura){
    delete [] estructura[indice];
    estructura[indice] = crearMatriz(ordenNueva);
}

void destruirEstructura(int ***estructura){
    delete [] estructura;
}
