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
    int intentos = 0; //Se inicializa el contador que
    int estadoUno = -1;
    int estadoDos = -1;
    int **resultado = new int*[sizeRegla - 1];
    for(int cont = 0; cont < sizeRegla - 1; cont++) resultado[cont] = new int[2];
    int ordenMin;
    bool enProceso = true;
    int enteroAux;
    bool boolAux;
    if(regla[0] >= regla[1]){
        ordenMin = regla[0];
    }
    else ordenMin = regla[1];

    if(ordenMin % 2 == 0) ordenMin += 1;
    else ordenMin += 2;

    if(regla[0] == regla[1] && regla[0] == 0) ordenMin = 3;

    int *ordenes = generarOrdenes(ordenMin, sizeRegla-1);
    int ***estructura = crearEstructura(ordenes, sizeRegla - 1);
    int *reglaFunc = new int[5]; reglaFunc[0] =  regla[0]; reglaFunc[1] = regla[1]; reglaFunc[2] = regla[2]; reglaFunc[3] = 0; reglaFunc[4] = 0;
    int *resulAux = new int[2];
    int *ordenAux = new int[2];
    for(int cont = 0; cont < sizeRegla - 2; cont++){
        ordenAux[0] = ordenes[cont];
        ordenAux[1] = ordenes[cont+1];
        while(enProceso){
            boolAux = encontrarComb(estructura[cont], estructura[cont+1], reglaFunc, resulAux, ordenAux, estadoUno, estadoDos);
            if(!boolAux){
                if(cont == 0){
                    ordenAux[0] += 2;
                    ordenes[0] += 2;
                    editarEstructura(enteroAux, ordenAux[enteroAux], estructura);
                }
                else{
                    ordenAux[1] += 2;
                    ordenes[cont + 1] += 2;
                    editarEstructura(cont + 1, ordenAux[1], estructura);
                }
            }
            else{
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
            intentos++;
            if(intentos > 50){
                resultado[0][0] = -1;
                return resultado;
            }
        }
        enProceso = true;
    }

    delete [] ordenAux;
    delete [] reglaFunc;
    delete [] ordenes;
    delete [] resulAux;
    destruirEstructura(estructura);
    return resultado;
}

bool encontrarComb(int **matrizUno, int **matrizDos, int *regla, int*arreglo, int* ordenes, int estadoUno, int estadoDos){
    int celdaUno;
    int celdaDos;
    bool isEstaticaUno = regla[3];
    bool isEstaticaDos = regla[4];
    int criterio = regla[2];
    int *celda = new int[2];
    bool finalizado = false;
    celda[0] = regla[0];
    celda[1] = regla[1];

    if(isEstaticaUno){
        celdaUno = obtenerRotacion(celda, matrizUno, ordenes[0], estadoUno);
    }
    if(isEstaticaDos){
        celdaDos = obtenerRotacion(celda, matrizDos, ordenes[1], estadoDos);
    }

    for(int cont = 0; cont < 4; cont++){
        if(!isEstaticaUno) {
            celdaUno = obtenerRotacion(celda, matrizUno, ordenes[0], cont);
        }
        for(int cont2 = 0; cont2 < 4; cont2++){
            if(!isEstaticaDos){
                celdaDos = obtenerRotacion(celda, matrizDos, ordenes[1], cont2);
            }
            if(criterio == -1 && celdaUno < celdaDos){
                finalizado = true;
            }
            else if(criterio == 1 && celdaUno > celdaDos){
                finalizado = true;
            }
            else if(criterio == 0 && celdaUno == celdaDos){
                finalizado = true;
            }

            if(finalizado){
               if(isEstaticaUno) arreglo[0] = estadoUno;
               else arreglo[0] = cont;

               if(isEstaticaDos) arreglo[1] = estadoDos;
               else arreglo[1] = cont2;

               delete [] celda;
               return true;
            }
            if(isEstaticaDos){
                cont2 = 3;
            }
        }
        if(isEstaticaUno){
            cont = 3;
        }
    }

    delete [] celda;
    return false;
}
