#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H


int** crearMatriz(int orden);
int ***crearEstructura(int *ordenes, int numMatrices);
int obtenerRotacion(int *posActual, int **matriz, int orden, int estado);
void destruirEstructura(int ***estructura);

#endif // ESTRUCTURAS_H
