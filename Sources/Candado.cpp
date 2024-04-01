#include "../Headers/Candado.h"
#include "../Headers/Estructuras.h"
#include "../Headers/Utilidades.h"

/**
 * Breve descripción de la función validarRegla.
 *
 * Permite validar una regla ingresada por el usuario
 *
 * @param regla Puntero que debe ser un arreglo de enteros, y representa la regla del candado.
 * @param sizeRegla Entero que representa el tamaño de la regla.
 * @return Devuelve un booleano queq indica si la regla es valida o no.
 */

bool validarRegla(int *regla, int sizeRegla){
    int ordenMin; //Se inicializa el orden minimo que va a tener un elemento de
    int medio; //Se inicializa el valor medio de la matriz de orden minimo.
    if(regla[0] < 0 || regla[1] < 0) return false; // Verifica que las coordenadas de la celda no sean negativas
    if(sizeRegla <= 2) return false; //Verifica que la longitud de la regla no sea inferior a 3
    for(int cont = 2; cont < sizeRegla; cont++){
        if(regla[cont] != 0 && regla[cont] != -1 && regla[cont] != 1) return false; //Para cada elemento de la regla verifica si es -1, 1 o 0.
    }

    //Las lineas de la 25 - 35 verifican que la celda no tenga coordenadas del punto medio de la matriz.
    if(regla[0] >= regla[1]){
        ordenMin = regla[0];
    }
    else ordenMin = regla[1];

    if(ordenMin % 2 == 0) ordenMin += 1;
    else ordenMin += 2;

    if(regla[0] == regla[1] && regla[0] == 0) ordenMin = 3;
    medio = ordenMin /2;
    if(regla[0] == medio && regla[1] == medio) return false;

    return true; //Entrega el boolean true, que indica que la regla es valida.
}

/**
 * Breve descripción de la función generarCandado.
 *
 * Permite hallar una configuracion de candado que cumpla una regla, si el algoritmo lo permite.
 *
 * @param regla Puntero que debe ser un arreglo de enteros, y representa la regla del candado.
 * @param sizeRegla Entero que representa el tamaño de la regla.
 * @return Devuelve una matriz que contiene el orden y el estado de cada estructura del candado generado (si el algoritmo encuentra una combinacion).
 */

int **generarCandado(int *regla, int sizeRegla){
    int intentos = 0; //Se inicializa el contador que cuenta los intentos que se han realizado para obtener una combinación dada.
    int estadoUno = -1; //Define el estado por defecto de la primera matriz a comparar. (se refiere a la primera matriz en cada comparación, no la primera de todas)
    int estadoDos = -1; //Define el estado por defecto de la segunda matriz a comparar. (se refiere a la segunda matriz en cada comparación, no la segunda de todas)
    int **resultado = new int*[sizeRegla - 1]; //Se define la matriz que va a contener los resultados y ordenes de las matrices.
    for(int cont = 0; cont < sizeRegla - 1; cont++) resultado[cont] = new int[2]; //Inicializa cada espacio de la matriz resultado como un arreglo de enteros.
    int ordenMin; //Orden minimo de cada matriz o estructura
    bool enProceso = true; //Variable que indica si esta en proceso de encontrar una combinacion o no.
    int enteroAux;
    bool boolAux;

    //Lineas de 62 - 70 sirven para determinar el orden minimo de la matriz segun la regla dada.
    if(regla[0] >= regla[1]){
        ordenMin = regla[0];
    }
    else ordenMin = regla[1];

    if(ordenMin % 2 == 0) ordenMin += 1;
    else ordenMin += 2;

    if(regla[0] == regla[1] && regla[0] == 0) ordenMin = 3;

    int *ordenes = generarOrdenes(ordenMin, sizeRegla-1); //Se genera un arreglo con los ordenes de las matrices en el candado
    int ***estructura = crearEstructura(ordenes, sizeRegla - 1); //Se crea una estructura que puede verse como un arreglo de matrices
    int *reglaFunc = new int[5]; reglaFunc[0] =  regla[0]; reglaFunc[1] = regla[1]; reglaFunc[2] = regla[2]; reglaFunc[3] = 0; reglaFunc[4] = 0; //Es la regla que se necesita para cada combinacion en la funcion encontrarComb
    int *resulAux = new int[2]; //Resultado auxiliar, este arreglo va a ser manejado por la funcion encontrarComb
    int *ordenAux = new int[2]; //Orden del par de matrices que se este comparando
    for(int cont = 0; cont < sizeRegla - 2; cont++){ //Ciclo for que va a coger cada criterio de la regla ingresada y adecuando las matrices para que todas los criterios se cumplan a cabalidad
        //Para cada iteración vuelve el primer elemento del arreglo ordenAux el orden de la primera matriz a comparar, analogamente se deduce el funcionamiento de la linea 80.
        ordenAux[0] = ordenes[cont];
        ordenAux[1] = ordenes[cont+1];
        while(enProceso){ //Ciclo que se ejecuta mientras no se encuentre una combinación valida para dos matrices.
            boolAux = encontrarComb(estructura[cont], estructura[cont+1], reglaFunc, resulAux, ordenAux, estadoUno, estadoDos); //Este booleano indica si se pudo encontrar una combinacion o no.
            if(!boolAux){ //Si no se pudo encontrar una combinación con esas dos matrices se aumentara el orden siguiendo los lineamientos comentados a continuacion:
                if(cont == 0){ //Si nos encontramos en la primera comparacion se genera un numero entre 0 y 1, con el fin de aumentar el orden de cualquiera de las dos matrices a comparar.
                    enteroAux = genRandom(0,1); //Se genera el numero aleatorio
                    //Se editan los ordenes según corresponda.
                    ordenAux[enteroAux] += 2;
                    ordenes[enteroAux] += 2;
                    editarEstructura(enteroAux, ordenAux[enteroAux], estructura); //Finalmente el arreglo de matrices se ve editado, poniendo en la estructura la nueva matriz con el nuevo orden.
                }
                else{ //Si no nos encontramos en la primera comparacion, se sabe que la segunda matriz de la comparación debe ser la que cambie, no la primera, porque si se cambia la primera podriamos alterar la correctitud del candado hasta el momento.
                    //Se realiza el mismo proceso que en el if anterior.
                    ordenAux[1] += 2;
                    ordenes[cont + 1] += 2;
                    editarEstructura(cont + 1, ordenAux[1], estructura);
                }
            }
            else{ //En este bloque de codigo se realizan las ediciones pertinentes a los arreglos que llevan control de los resultados correctos, posteriormente se vuelve falso el booleano enProceso.
                //Y la primera matriz de la comparación se vuelve estatica.
                if(cont == 0){
                    if(sizeRegla >= 4){
                        reglaFunc[2] = regla[3]; reglaFunc[3] = 1;
                    }
                    resultado[0][0] = ordenAux[0]; resultado[0][1] = resulAux[0]; resultado[1][0] = ordenAux[1]; resultado[1][1] = resulAux[1];
                }
                else resultado[cont + 1][0] = ordenAux[1];  resultado[cont+1][1] = resulAux[1]; reglaFunc[2] = regla[3 + cont];
                enProceso = false;
                estadoUno = resulAux[1];
            }
            intentos++; //Se aumenta el contador de intentos
            if(intentos > 50){ //Si hay mas de 50 intentos se edita el valor del apuntador resultado para dejalo como -1, eso nos indicará despues que nuestro algoritmo no pudo encontrar una combinacion.
                resultado[0][0] = -1;
                return resultado;
            }
        }
        intentos = 0; //Para cada comparacion se reinicia el contador de intentos y el booleano enProceso se deja verdadero.
        enProceso = true;
    }

    //Finalmente se libera memoria para evitar la fuga de datos.
    delete [] ordenAux;
    delete [] reglaFunc;
    delete [] ordenes;
    delete [] resulAux;
    destruirEstructura(estructura);
    return resultado;
}

/**
 * Breve descripción de la función encontrarComb.
 *
 * Permite hallar una combinacion de estados entre dos matrices que cumpla un criterio dado.
 *
 * @param matrizUno Primera matriz en la comparacion.
 * @param matrizDos Segunda matriz en la comparacion.
 * @param regla Arreglo que contiene 5 entradas, primera y segunda son las coordenadas de la celda, tercera es el criterio y cuarta y quinta se refieren a si la matriz uno o dos es estatica (no es la regla dada por el usuario).
 * @param arreglo Arreglo donde se guardaran los estados que hacen que el criterio dado se cumpla.
 * @param ordenes Arreglo de exactamente dos posiciones que contiene el orden de la matriz uno y la matriz dos.
 * @param estadoUno Contiene el estado en el cual la matrizUno va a estar estatica, si es -1, entonces la matriz no sera estatica.
 * @param estadoUno Contiene el estado en el cual la matrizDos va a estar estatica, si es -1, entonces la matriz no sera estatica.
 * @return Devuelve un booleano, true si se encontró la combinacion de estados que cumpla el criterio, y false si no se pudo encontrar dicha combinacion.
 */

bool encontrarComb(int **matrizUno, int **matrizDos, int *regla, int*arreglo, int* ordenes, int estadoUno, int estadoDos){
    int celdaUno; //Define variables para el numero que hay en la celda a comparar en la matriz uno y dos.
    int celdaDos;
    bool isEstaticaUno = regla[3]; //Define booleanos que indican si la matriz uno o dos son estaticas.
    bool isEstaticaDos = regla[4];
    int criterio = regla[2]; //Criterio de comparacion entre las dos matrices (1, -1 ,0).
    int *celda = new int[2]; //Arreglo que contendra las coordenadas de la celda.
    bool finalizado = false; //Indica si se encontro la combinacion deseada.
    celda[0] = regla[0]; //Asigna a las posicoines del arreglo celda, las coordenadas contenidas en la regla.
    celda[1] = regla[1];


    //De la linea 157 a 162 se le asigna una celda invariable a la matriz correspondiente en el caso de que sea estatica.
    if(isEstaticaUno){
        celdaUno = obtenerRotacion(celda, matrizUno, ordenes[0], estadoUno);
    }
    if(isEstaticaDos){
        celdaDos = obtenerRotacion(celda, matrizDos, ordenes[1], estadoDos);
    }

    for(int cont = 0; cont < 4; cont++){ //Ciclo while que va a iterar entre todos los estados posibles de la matrizUno, del 0 al 3.
        if(!isEstaticaUno) { //Se obtiene el valor de la celda dada en el estado que indique el contador.
            celdaUno = obtenerRotacion(celda, matrizUno, ordenes[0], cont);
        }
        for(int cont2 = 0; cont2 < 4; cont2++){ //Ciclo while que va a iterar entre todos los estados posibles de la matrizDos, del 0 al 3.
            if(!isEstaticaDos){ //Se obtiene el valor de la celda dada en el estado que indique el contador2.
                celdaDos = obtenerRotacion(celda, matrizDos, ordenes[1], cont2);
            }

            //En 173 - 182 se evalua si los numeros en las celdas de las dos matrices cumplen cada uno de los criterios.
            if(criterio == -1 && celdaUno < celdaDos){
                finalizado = true;
            }
            else if(criterio == 1 && celdaUno > celdaDos){
                finalizado = true;
            }
            else if(criterio == 0 && celdaUno == celdaDos){
                finalizado = true;
            }

            if(finalizado){ //Si las celdas cumplen el criterio se modifica el arreglo 'arreglo' y se le pone el estado para cada matriz que permitio que el criterio se cumpliera.
               if(isEstaticaUno) arreglo[0] = estadoUno;
               else arreglo[0] = cont;

               if(isEstaticaDos) arreglo[1] = estadoDos;
               else arreglo[1] = cont2;

               delete [] celda; //se libera memoria
               return true;
            }
            if(isEstaticaDos){ //Si es estatica se lleva el contador a 3, esto con el fin de terminar el ciclo.
                cont2 = 3;
            }
        }
        if(isEstaticaUno){ //Si es estatica se lleva el contador a 3, esto con el fin de terminar el ciclo.
            cont = 3;
        }
    }

    delete [] celda; //Se libera memoria
    return false;
}
