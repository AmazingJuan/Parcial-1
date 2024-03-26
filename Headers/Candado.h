#ifndef CANDADO_H
#define CANDADO_H

bool validarRegla(int *regla, int sizeRegla);


int **generarCandado(int *regla, int sizeRegla);

int *primeraComb(int **matrizUno, int **matrizDos, int *resultado);

#endif // CANDADO_H
