#include <iostream>
#include "Headers/Candado.h"
#include "Headers/Estructuras.h"
#include "Headers/Menus.h"
using namespace std;

int main(){
    int ***estructResult = nullptr;
    string *opcVisualizacion = new string[1];
    opcVisualizacion[0] = "1";
    int **configCandado = nullptr;
    int contAux = 1;
    int fila;
    int columna;
    int opcCriterio = 0;
    int opcMatrices = 0;
    int *regla = nullptr;
    string *opcionesCriterio = new string[4]; opcionesCriterio[0] = "1"; opcionesCriterio[1] = "2"; opcionesCriterio[2] = "3"; opcionesCriterio[3] = "4";
    string criterios = "";
    string **opcEst = nullptr;
    bool bandera = true;
    while(bandera){
        limpiarPantalla();
        cout << obtenerMensaje(1);
        //congelarPantalla(7);
        limpiarPantalla();
        fila = menuNumero(obtenerMensaje(2), "la fila de la celda");
        columna = menuNumero(obtenerMensaje(3), "la columna de la celda");
        while(opcCriterio != 4){
            opcCriterio = menuOpcion(obtenerMensaje(4) + to_string(contAux) + " y " + to_string(contAux + 1) + ":\n\n1. 1 - La celda de la primera estructura debe ser mayor a la celda de la segunda estructura\n2. 0 - La celda de la primera estructura debe ser igual a la celda de la segunda estructura\n3. -1 - La celda de la primera estructura debe ser menor a la celda de la segunda estructura\n4. Presione esta opcion si termino de ingresar los criterios para la regla\n\n"  , opcionesCriterio, 4);
            if(opcCriterio != 4) {
                criterios += to_string(opcCriterio);
                contAux++;
            }
        }
        regla = formarRegla(fila, columna, criterios);
        cout << "PASE ESTO";
        if(validarRegla(regla, 2 + criterios.size())){
            configCandado = generarCandado(regla, 2 + criterios.size());
                    cout << "PASE ESTO";
                    cout << "PASE ESTO";
            opcEst = generarOpciones(contAux);
                            cout << "PASE ESTO";
            while(opcMatrices < contAux + 1){
                opcMatrices = menuOpcion(obtenerMensaje(6) + opcEst[1][0], opcEst[0], contAux + 2);
                if(opcMatrices < contAux + 1) {
                    menuOpcion(obtenerMensaje(7) + stringMatriz(configCandado[opcMatrices - 1][0], configCandado[opcMatrices - 1][1]) + "\n1. Seleccione esta opcion para volver al menu de visualizacion de estructuras.\n\n", opcVisualizacion, 1);
                }
                else if(opcMatrices == (contAux + 2)) bandera = false;
            }
            opcCriterio = 0;
            opcMatrices = 0;
        }
        else{
            limpiarPantalla();
            cout << obtenerMensaje(5);
            congelarPantalla(5);
        }
    }

}
