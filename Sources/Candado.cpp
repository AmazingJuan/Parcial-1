#include "../Headers/Candado.h"
#include "../Headers/Estructuras.h"
#include "../Headers/Utilidades.h"

bool validarRegla(int *regla, int sizeRegla){
    if(regla[0] <= 0 && regla[1] <= 0) return false;
    if(sizeRegla <= 2) return false;
    for(int cont = 2; cont < sizeRegla; cont++){
        if(regla[cont] != 0 && regla[cont] != -1 && regla[cont] != 1) return false;
    }
    return true;
}


int **generarCandado(int *regla, int sizeRegla){
    int **resultado = new int*[sizeRegla - 1];
    for(int cont = 0; cont < sizeRegla - 1; cont++) resultado[cont] = new int[2];
    int ordenMin;
    bool enProceso = true;
    int enteroAux;
    bool boolAux;
    if(regla[0] >= regla[1]) ordenMin = regla[0] + 1;
    else ordenMin = regla[1] + 1;
    int *ordenes = generarOrdenes(ordenMin, sizeRegla-1);
    int ***estructura = crearEstructura(ordenes, sizeRegla - 1);
    int *reglaFunc = new int[5]; reglaFunc[0] =  regla[0]; reglaFunc[1] = regla[1]; reglaFunc[2] = regla[2]; reglaFunc[3] = 0; reglaFunc[4] = 0;
    int *resulAux = new int[2];
    int *ordenAux = new int[2];
    for(int cont = 0; cont < sizeRegla -2; cont++){
        ordenAux[0] = ordenes[cont];
        ordenAux[1] = ordenes[cont+1];
        while(enProceso){
            boolAux = encontrarComb(estructura[cont], estructura[cont], reglaFunc, resulAux, ordenAux);
            if(boolAux == false){
                if(cont == 0){
                    enteroAux = genRandom(0, 1);
                    ordenAux[enteroAux] += 2;
                    ordenes[cont + enteroAux] += 2;
                    editarEstructura(cont + enteroAux, ordenAux[enteroAux], estructura);
                }
                else{
                    ordenAux[1] += 2;
                    ordenes[cont + 1] += 2;
                    editarEstructura(cont + 1, ordenAux[1], estructura);
                }
            }
            else{
                if(cont == 0){
                    reglaFunc[2] = regla[3 + cont]; reglaFunc[3] = 1;
                    resultado[0][0] = ordenAux[0]; resultado[0][1] = resulAux[0]; resultado[1][0] = ordenAux[1]; resultado[1][1] = resulAux[1];
                }
                else resultado[cont + 1][0] = ordenAux[1];  resultado[cont+1][1] = resulAux[1];
                enProceso = false;
            }
        }
        enProceso = true;
    }
    delete [] ordenAux;
    delete [] reglaFunc;
    delete [] ordenes;
    delete [] resulAux;

    return resultado;
}

bool encontrarComb(int **matrizUno, int **matrizDos, int *regla, int*arreglo, int* ordenes){
    int celdaUno = matrizUno[regla[0]][regla[1]];
    int celdaDos = matrizDos[regla[0]][regla[1]];
    bool isEstaticaUno = regla[3];
    bool isEstaticaDos = regla[4];
    int criterio = regla[2];
    int *celda = new int[2];
    int estadoUno = 0;
    int estadoDos = 0;
    bool finalizado = false;
    celda[0] = regla[0];
    celda[1] = regla[1];

    for(int cont = 0; cont < 4; cont++){
        if(!isEstaticaUno) {
            celdaUno = obtenerRotacion(celda, matrizUno, ordenes[0], cont);
        }
        else cont = 3;
        for(int cont2 = 0; cont2 < 4; cont2++){
            if(!isEstaticaDos){
                celdaDos = obtenerRotacion(celda, matrizDos, ordenes[1], cont2);
            }
            else cont2 = 3;

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
               arreglo[0] = estadoUno;
               arreglo[1] = estadoDos;
               delete [] celda;
               return true;
           }
            if(!isEstaticaDos){
               estadoDos++;
           }
        }
        if(!isEstaticaUno){
            estadoUno++;
        }
        estadoDos = 0;
    }
    delete [] celda;
    return false;
}
