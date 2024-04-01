#include "../Headers/Estructuras.h"


/**
 * Breve descripción de la función crearMatriz.
 *
 * Permite crear una matriz y llenarla segun las consideraciones iniciales.
 *
 * @param orden Orden de la matriz deseada.
 * @return Devuelve un puntero que apunta al primer elemento de la matriz.
 */

int** crearMatriz(int orden){
    int medio = (orden / 2); //Se encuentra el punto medio de la matriz.
    int contAux = 1; //Se inicia un contador auxiliar que va a ser el primer numero que se ubique en la posicion [0][0] de la matriz.
    int **matriz = new int*[orden]; //Se aloja memoria para la matriz.
    for(int fila = 0; fila < orden; fila++){
        matriz[fila] = new int[orden]; //Se crea un arrelgo de enteros en cada fila de la matriz.
        for(int columna = 0; columna < orden; columna++){
            if(fila == medio && columna == medio){ //Si se trata de la coordenada media de la matriz, entonces se asigna -1 y no se actualiza el contador auxiliar.
                matriz[fila][columna] = -1; //El -1 indicará que es un espacio en blanco mas adelante.
            }
            else{
                matriz[fila][columna] = contAux; //Se asigna el valor del contador auxiliar si la coordenada actual no es el punto medio.
                contAux++;
            }
        }
    }
    return matriz;
}


/**
 * Breve descripción de la función crearEstructura.
 *
 * Permite crear un arreglo de matrices.
 *
 * @param ordenes Arreglo con todos los ordenes de las matrices deseadas.
 * @param numMatrices Cantidad de matrices que habra en la estructura.
 * @return Devuelve un puntero que apunta al primer elemento de la primera matriz de la estructura.
 */

int ***crearEstructura(int *ordenes, int numMatrices){
    int ***estructuraPtr = new int**[numMatrices]; //Se aloja memoria para la estructura
    for(int cont = 0; cont < numMatrices; cont++){ //Se llena la estructura haciendo uso de la funcion crearMatriz.
        estructuraPtr[cont] = crearMatriz(ordenes[cont]);
    }
    return estructuraPtr;
}


/**
 * Breve descripción de la función obtenerRotacion.
 *
 * Permite obtener el numero en una celda dada de una matriz que tiene un estado dado.
 *
 * @param posActual Arreglo con las coordenadsa de la celda deseada.
 * @param matriz Matriz a la cual se le quiere obtener la celda (debe estar en su estado neutral).
 * @param orden Orden de la matriz.
 * @param estado Estado de la matriz.
 * @return Devuelve un entero que es el valor que tendria la matriz en la celda dada si estuviera en un estado dado.
 */

int obtenerRotacion(int *posActual, int **matriz, int orden, int estado){
    int medio = orden / 2; //Ubica el punto medio de la matriz.
    int fila = posActual[0]; //Se define la fila y columna, creando a su vez una copia de esta fila para no perder el valor
    int filaAux = fila;
    int columna = posActual[1];
    fila = columna; //Se identifica que cuando se va de un estado a otro la fila se vuelve la columna.
    columna = 2*medio - filaAux; //Se identifica tambien que la columna va a ser igual a la diferencia entre el doble del medio y la fila dada.

    if(estado == 1) return matriz[fila][columna]; //Se devuelve el valor requerido si el estado es 1, sino sucede esto entonces se realiza el mismo proceso hasta el estado 3.
    else if(estado == 2){
        filaAux = fila;
        fila = columna;
        columna = 2*medio - filaAux;
        return matriz[fila][columna];
    }
    else if(estado == 3){
        filaAux = fila;
        fila = columna;
        columna = 2*medio - filaAux;
        return matriz[fila][columna];
    }
    else return matriz[posActual[0]][posActual[1]]; //Si el estado es 0, entonces se devuelve el valor de la matriz en la fila y columna originales.
}

/**
 * Breve descripción de la función generarOrdenes.
 *
 * Genera un arreglo los cuales todos tienen el mismo valor, que va a ser un orden dado.
 *
 * @param orden Valor que deben compartir todos los elementos del arreglo.
 * @param tamano Tamaño del arreglo.
 * @return Devuelve el puntero que esta asociado al primer elemento del arreglo.
 */

int *generarOrdenes(int orden, int tamano){
    int *ordenes = new int[tamano]; //Se crea un arreglo de enteros.
    for(int cont = 0; cont < tamano; cont++) ordenes[cont] = orden; //Para cada celda se le asigna el mismo valor.
    return ordenes;
}


/**
 * Breve descripción de la función editarEstructura.
 *
 * Permite obtener el numero en una celda dada de una matriz que tiene un estado dado.
 *
 * @param indice Posicion del arreglo de matrices (estructura) que va a ser editado.
 * @param ordenNueva Orden de la nueva matriz que va a ser insertada en la posicion de la vieja matriz.
 * @param estructura Arreglo de matrices (estructura) al cual se le quiere hacer el cambio.
 * @return Ninguno, simplemente edita por referencia la estrucutra.
 */

void editarEstructura(int indice, int ordenNueva, int ***estructura){
    delete [] estructura[indice]; //Se libera la memoria de la vieja matriz.
    estructura[indice] = crearMatriz(ordenNueva); //Se inserta la nueva matriz a la estructura
}


/**
 * Breve descripción de la función destruirEstructura.
 *
 * Se libera memoria de una estructura que se ha creada previamente.
 *
 * @param estructura Arreglo de matrices el cual debe ser liberado de la memoria.
 * @return Ninguno, simplemente libera la memoria ocupada por la estructura.
 */

void destruirEstructura(int ***estructura){
    delete [] estructura; //Libera memoria ocupada por la estructura.
}


/**
 * Breve descripción de la función formarRegla.
 *
 * Genera un arreglo que contiene la regla ingresada por el usuario.
 *
 * @param fila Arreglo con las coordenadsa de la celda deseada.
 * @param columna Matriz a la cual se le quiere obtener la celda (debe estar en su estado neutral).
 * @param criterios Orden de la matriz.
 * @return Devuelve un arreglo que contine la regla ingresada por el usuario.
 */

int *formarRegla(int fila, int columna, string criterios){
    int *regla = new int[2 + criterios.size()]; //Se aloja memoria para el arreglo deseado, en este caso se suma el tamaño del string criterio y el espacio para la fila y columna de la celda.
    regla[0] = fila - 1; //Se le resta 1 a la celda y columan ingresada por el usuario.
    regla[1] = columna - 1;
    for(int cont = 0; cont < criterios.size(); cont++){ //Recorre todos los elementos del string criterio, estos pueden ser '1', '2' o '3', significa que el criterio sera 1, 0 o -1 respectivamente. La decision de implementar los criterios de esta manera tiene que ver con el menu.
        if(criterios.at(cont) == '1') regla[2 + cont] = 1;
        else if(criterios.at(cont) == '2') regla[2 +cont] = 0;
        else regla[2 + cont] = -1;
    }
    return regla;
}
