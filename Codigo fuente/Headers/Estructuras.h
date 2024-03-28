#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H


int** crearMatriz(int orden);
int **rotarMatriz(int **matriz, int orden, int estado);
int ***crearEstructura(int *ordenes, int numMatrices);
int *generarOrdenes(int orden, int tamano);
int obtenerRotacion(int *posActual, int **matriz, int orden, int estado);
void editarEstructura(int indice, int ordenNueva, int ***estructura);
void destruirEstructura(int ***estructura);

#endif // ESTRUCTURAS_H
