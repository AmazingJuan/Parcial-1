#include "../Headers/Importaciones.h"
#include "../Headers/Validacion.h"
#include "../Headers/Utilidades.h"

bool validarOpcion(string entrada, string *opciones, int lenOpciones){
    if(entrada.size() == 0) return false;
    return stringInArray(entrada, opciones, lenOpciones);
}
