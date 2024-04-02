#include "../Headers/Importaciones.h"
#include "../Headers/Validacion.h"
#include "../Headers/Utilidades.h"

/**
 * Breve descripción de la función validarOpcion.
 *
 * Verifica que una entrada dada tenga longitud mayor que cero y este en un arreglo de opciones.
 *
 * @param entrada String a verificar.
 * @param opciones Arreglo de strings que contiene las opciones.
 * @param lenOpciones Entero que indica la longitud del arreglo de opciones.
 * @return Booleano que indica si la entrada es valida o no, es decir si esta en el arreglo y tiene longitud diferente de 0.
 */

bool validarOpcion(string entrada, string *opciones, int lenOpciones){
    if(entrada.size() == 0) return false;
    return stringInArray(entrada, opciones, lenOpciones); //Se llama a la funcion stringInArray.
}

/**
 * Breve descripción de la función validarNumero.
 *
 * Verifica que una entrada dada sea un numero positivo, y no nula.
 *
 * @param entrada String a verificar.
 * @return Booleano que indica si la entrada es valida o no, es decir si es un numero positivo de longitud distinta de 0.
 */

bool validarNumero(string entrada){
    string numeros = "0123456789"; //Se inicializa un string que contiene todos los numeros
    if(entrada.size() == 0) return false; //Se verifica que la entrada tenga longitud distinta de 0
    for(int cont = 0; cont < entrada.size(); cont++){
        if(numeros.find(entrada.at(cont)) >= numeros.size()) return false; //Para cada caracter de la entrada se verifica si pertenece al string de numeros, sino se devuelve falso.
    }
    return stoi(entrada) > 0 ? true: false; //Se devuelve verdadero si la entrada es mayor que cero, de lo contrairo se devuelve falso.
}
