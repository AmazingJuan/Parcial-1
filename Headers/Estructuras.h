#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H


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




#endif // ESTRUCTURAS_H
