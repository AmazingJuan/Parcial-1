#ifndef MENUS_H
#define MENUS_H

#include "string"
#include "Utilidades.h"
#include "Validacion.h"

int menuOpcion(string mensaje, string* opciones, int lenOpcion);
int menuNumero(string mensaje, string tipoEntrada);

#endif // MENUS_H
