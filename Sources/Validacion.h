#ifndef VALIDACION_H
#define VALIDACION_H

#include "../Headers/Importaciones.h"

bool validarOpcion(string entrada, string *opciones, int lenOpciones){
    if(entrada.size() == 0) return false;
    return stringInArray(entrada, opciones, lenOpciones);
}

#endif // VALIDACION_H
