#include "../Headers/Menus.h"

int menuOpcion(string mensaje, string* opciones, int lenOpcion){
    bool bandera = true;
    bool error = false;
    string entrada = "";
    while(bandera){
        limpiarPantalla();
        cout << mensaje;
        if(!error) cout << "Escoja la opcion que desee: ";
        else cout << "Ingreso una opcion incorrecta, vuelva a ingresar la opcion por favor: ";
        getline(cin, entrada);
        if(validarOpcion(entrada, opciones, lenOpcion)) {
            return stoi(entrada);
        }
        else error = true;
    }
}

int menuNumero(string mensaje, string tipoEntrada){
    bool bandera = true;
    bool error = false;
    string entrada = "";
    while(bandera){
        limpiarPantalla();
        cout << mensaje;
        if(!error) cout << "Ingrese " + tipoEntrada + ": ";
        else cout << "Ingreso una opcion incorrecta, vuelva a ingresar " + tipoEntrada + ": ";
        getline(cin, entrada);
        if(validarNumero(entrada)){
            return stoi(entrada);
        }
        else error = true;
    }
}
