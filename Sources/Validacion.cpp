#include "../Headers/Importaciones.h"
#include "../Headers/Validacion.h"
#include "../Headers/Utilidades.h"

bool validarOpcion(string entrada, string *opciones, int lenOpciones){
    if(entrada.size() == 0) return false;
    return stringInArray(entrada, opciones, lenOpciones);
}

bool validarNumero(string entrada){
    string numeros = "0123456789";
    if(entrada.size() == 0) return false;
    for(int cont = 0; cont < entrada.size(); cont++){
        if(numeros.find(entrada.at(cont)) >= numeros.size()) return false;
    }
    return stoi(entrada) > 0 ? true: false;
}
