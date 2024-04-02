#include <iostream>
#include "Headers/Candado.h"
#include "Headers/Estructuras.h"
#include "Headers/Menus.h"
using namespace std;

/*
      Programa       : Main.java
      Programadores  : Juan Avendaño y Freddy Castaño
      Descripción    : Parcial 1 - Informatica 2
      Fecha creación : 26 de marzo de 2024
      Revisión       : Ninguna
*/

int main(){
    string *opcVisualizacion = new string[1]; //Se crea un arreglo de un solo string que servira para volver al menu de visualizacion cuando el usuario este visualizando una matriz dada.
    opcVisualizacion[0] = "1"; //Se le asigna a la unica opción el uno.
    int **configCandado = nullptr; //Se inicializa un puntero que va a contener la configuracion del candado, apunte a un puntero nulo.
    int contAux = 1; //Contador que va a llevar cuenta de las matrices que ingrese el usuario
    int fila; //Fila de la celda.
    int columna; //Columna de la celda.
    int opcCriterio = 0; //Opcion escogida cuando el usuario va a elegir un criterio.
    int opcMatrices = 0; //Opcion escogida cuando el usuario va a escoger una de las matrices a visualizar.
    int *regla = nullptr;
    string *opcionesCriterio = new string[4]; opcionesCriterio[0] = "1"; opcionesCriterio[1] = "2"; opcionesCriterio[2] = "3"; opcionesCriterio[3] = "4"; //Crea las opciones que tendrá el usuario cuando se disponga a escoger un criterio
    string criterios = ""; //String que alamacena los criterios que el usuario escoja.
    string **opcEst = nullptr; //Puntero que apunta a uno nulo, este me representará las opciones de visualizacion cuando ya se haya encontrado una combinacion.
    bool bandera = true; //Bandera que me controla si el programa ya finalizó
    while(bandera){
        limpiarPantalla(); //Para cada iteracion de este ciclo while se le muestra en la pantalla al usuario un mensaje de bienvenida por unos segundos.
        cout << obtenerMensaje(1);
        congelarPantalla(7);
        limpiarPantalla();
        //Se le pide al usuario la fila y columna que desea asignar como celda.
        fila = menuNumero(obtenerMensaje(2), "la fila de la celda");
        columna = menuNumero(obtenerMensaje(3), "la columna de la celda");
        while(opcCriterio != 4){//El siguiente while funciona para recibir criterios por parte del usuario para comparar las matrices hasta que presione el numero 4, que es para finalizar de poner criterios.
            //La linea siguiente es la que abre el menu con el mensaje pertinente y recibe la entrada del usuario.
            opcCriterio = menuOpcion(obtenerMensaje(4) + to_string(contAux) + " y " + to_string(contAux + 1) + ":\n\n1. 1 - La celda de la primera estructura debe ser mayor a la celda de la segunda estructura\n2. 0 - La celda de la primera estructura debe ser igual a la celda de la segunda estructura\n3. -1 - La celda de la primera estructura debe ser menor a la celda de la segunda estructura\n4. Presione esta opcion si termino de ingresar los criterios para la regla\n\n"  , opcionesCriterio, 4);
            if(opcCriterio != 4) { //Se evalua si la opción fue 4 o no, en caso negativo se añade la opcion que el usuario eligio al string de criterios, y posteriormente se aumenta el contador de matrices.
                criterios += to_string(opcCriterio);
                contAux++;
            }
        }
        regla = formarRegla(fila, columna, criterios); //Se forma la regla como arreglo de enteros.
        if(validarRegla(regla, 2 + criterios.size())){ //Si la regla es valida se ejecuta todo el proceso para  buscar la combinacion.
            configCandado = generarCandado(regla, 2 + criterios.size()); //Se genera la combinación.
            if(configCandado[0][0] != -1){ //Si la combinacion tiene un -1 en la coordenada [0][0], entonces no se pudo encontrar la combinacion, en caso de que si se haya podido realizar lo anterior se prosigue con este if.
                opcEst = generarOpciones(contAux); //Se generan las opciones de visualizacion para el usuario.
                while(opcMatrices < contAux + 1){ //Mientras que el usuario no escoja la opcion contAux + 1 o contAux + 2 se ejecutara el while.
                    opcMatrices = menuOpcion(obtenerMensaje(6) + opcEst[1][0], opcEst[0], contAux + 2); //Le da a escoger el usuario las matrices que puede visualizar.
                    if(opcMatrices < contAux + 1) { //Si la opcion corresponde a visualizar alguna de las matrices disponibles, entonces se abre otro menu con la matriz y sus detalles, y puede devolverse cuando quiera.
                        menuOpcion(obtenerMensaje(7) + stringMatriz(configCandado[opcMatrices - 1][0], configCandado[opcMatrices - 1][1]) + "\n1. Seleccione esta opcion para volver al menu de visualizacion de estructuras.\n\n", opcVisualizacion, 1);
                    }
                    else if(opcMatrices == (contAux + 2)) bandera = false; //En caso de que seleccione salir del programa la bandera de control de ejecucion se vuelve falsa, y se para el ciclo while de la linea 29.
                }
            }
            else{ //Si no se pudo encontrar una combinacion valida, entonces se lo hace saber al usuario y se vuelve a ejecutar el programa.
                limpiarPantalla();
                cout << obtenerMensaje(5) << "No pudimos encontrar una combinacion de matrices para la regla dada, volviendo al menu principal...";
                congelarPantalla(5);
            }
        }
        else{ //Si la regla es invalida se lo hace saber al usuario y se vuelve a ejecutar el programa.
            limpiarPantalla();
            cout << obtenerMensaje(5) << "Usted ingreso una regla invalida, volviendo al menu principal...";
            congelarPantalla(5);
        }
        //Se reinician las variables que mutan en la ejecucion a su estado inicial.
        opcCriterio = 0;
        opcMatrices = 0;
        contAux = 0;
        criterios = "";
    }
    //Cuando el usuario sale del programa se le muestra un mensaje de despedida y se le agradece por usar el programa.
    limpiarPantalla();
    cout << obtenerMensaje(8);
    congelarPantalla(5);
    //Se libera la memoria de todas las variables donde se reservo memoria.
    delete [] regla;
    delete [] opcEst;
    delete [] configCandado;
    delete [] opcVisualizacion;
    delete [] opcionesCriterio;
    return 0;
}
