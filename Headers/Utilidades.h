#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "Importaciones.h"
#include "Estructuras.h"
#include <thread>

int genRandom(int menor, int mayor);
void limpiarPantalla();
bool stringInArray(string cadena, string* arreglo, int lenArreglo);
string *obtenerOpciones();
string obtenerMensaje(int parametro);
void congelarPantalla(int segundos);
string stringMatriz(int orden, int estado);
string **generarOpciones(int numMatrices);

#endif // UTILIDADES_H
