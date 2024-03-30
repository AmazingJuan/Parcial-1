#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include "Importaciones.h"
int** crearMatriz(int orden);
int ***crearEstructura(int *ordenes, int numMatrices);
int *generarOrdenes(int orden, int tamano);
int obtenerRotacion(int *posActual, int **matriz, int orden, int estado);
void editarEstructura(int indice, int ordenNueva, int ***estructura);
int *formarRegla(int fila, int columna, string criterios);
void destruirEstructura(int ***estructura);

#endif // ESTRUCTURAS_H
