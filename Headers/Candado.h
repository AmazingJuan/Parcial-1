#ifndef CANDADO_H
#define CANDADO_H

bool validarRegla(int *regla, int sizeRegla);


int **generarCandado(int *regla, int sizeRegla);

bool encontrarComb(int **matrizUno, int **matrizDos, int *regla, int*arreglo, int* ordenes);

#endif // CANDADO_H
