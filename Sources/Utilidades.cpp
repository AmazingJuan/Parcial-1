#import "../Headers/Utilidades.h"


int genRandom(int menor, int mayor){ //fue sacada de internet
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(menor, mayor);
    return dist(gen);
}

void limpiarPantalla(){
    for(int cont = 0; cont < 50; cont++) cout << "\n";
}

bool stringInArray(string cadena, string* arreglo, int lenArreglo){
    for(int cont = 0; cont < lenArreglo; cont ++) if(cadena == arreglo[cont]) return true;
    return false;
}

string obtenerMensaje(int parametro){
    switch (parametro){
        case 1:
            return "  ____    _                                         _       _         \n |  _ \\  (_)                                       (_)     | |        \n | |_) |  _    ___   _ __   __   __   ___   _ __    _    __| |   ___  \n |  _ <  | |  / _ \\ | '_ \\  \\ \\ / /  / _ \\ | '_ \\  | |  / _` |  / _ \\ \n | |_) | | | |  __/ | | | |  \\ V /  |  __/ | | | | | | | (_| | | (_) |\n |____/  |_|  \\___| |_| |_|   \\_/    \\___| |_| |_| |_|  \\__,_|  \\___/ \n\nBienvenido al Desafio 1, en unos momentos podra ingresar la regla para generar el candado...";
        case 2:
            return "  ______   _   _         \n |  ____| (_) | |        \n | |__     _  | |   __ _ \n |  __|   | | | |  / _` |\n | |      | | | | | (_| |\n |_|      |_| |_|  \\__,_|\n                         \n";
        case 3:
            return "   _____           _                                     \n  / ____|         | |                                    \n | |        ___   | |  _   _   _ __ ___    _ __     __ _ \n | |       / _ \\  | | | | | | | '_ ` _ \\  | '_ \\   / _` |\n | |____  | (_) | | | | |_| | | | | | | | | | | | | (_| |\n  \\_____|  \\___/  |_|  \\__,_| |_| |_| |_| |_| |_|  \\__,_|\n                                                         \n";
        case 4:
            return "   _____          _   _                   _         \n  / ____|        (_) | |                 (_)        \n | |       _ __   _  | |_    ___   _ __   _    ___  \n | |      | '__| | | | __|  / _ \\ | '__| | |  / _ \\ \n | |____  | |    | | | |_  |  __/ | |    | | | (_) |\n  \\_____| |_|    |_|  \\__|  \\___| |_|    |_|  \\___/ \n                                                    \nHe aqui los criterios de comparacion disponibles para las estructuras ";
        case 5:
            return "  ______                              \n |  ____|                             \n | |__     _ __   _ __    ___    _ __ \n |  __|   | '__| | '__|  / _ \\  | '__|\n | |____  | |    | |    | (_) | | |   \n |______| |_|    |_|     \\___/  |_|   \n                                      \nUsted ingreso una regla invalida, volviendo al menu principal...";
        case 6:
            return "  ______          _   _          _       _               _              \n |  ____|        | | (_)        (_)     | |             | |             \n | |__      ___  | |  _    ___   _    __| |   __ _    __| |   ___   ___ \n |  __|    / _ \\ | | | |  / __| | |  / _` |  / _` |  / _` |  / _ \\ / __|\n | |      |  __/ | | | | | (__  | | | (_| | | (_| | | (_| | |  __/ \\__ \\\n |_|       \\___| |_| |_|  \\___| |_|  \\__,_|  \\__,_|  \\__,_|  \\___| |___/\n                                                                       \nFelicidades, hemos encontrado una combinacion de candado para la regla que usted especifico, fijese en las opciones que le brindamos:\n\n";
        case 7:
            return " __      __  _                         _   _                     _                \n \\ \\    / / (_)                       | | (_)                   | |               \n  \\ \\  / /   _   ___   _   _    __ _  | |  _   ____   __ _    __| |   ___    _ __ \n   \\ \\/ /   | | / __| | | | |  / _` | | | | | |_  /  / _` |  / _` |  / _ \\  | '__|\n    \\  /    | | \\__ \\ | |_| | | (_| | | | | |  / /  | (_| | | (_| | | (_) | | |   \n     \\/     |_| |___/  \\__,_|  \\__,_| |_| |_| /___|  \\__,_|  \\__,_|  \\___/  |_|   \n                                                                                   \nHe aqui la informacion de la Estructura ";
        default:
            return "";
    }
}

void congelarPantalla(int segundos){
    this_thread::sleep_for(segundos * 1000ms);
}

string stringMatriz(int orden, int estado){
    int **matriz = crearMatriz(orden);
    string estadoAux;
    int *posAux = new int[2];
    if(estado == 0) estadoAux = "Neutral";
    else estadoAux = to_string(estado);
    string resultado = "Orden: " + to_string(orden) + "\nEstado: " + estadoAux + "\n\nMatriz solicitada:\n\n";
    for(int fila = 0; fila < orden; fila++){
        posAux[0] = fila;
        for(int columna = 0; columna < orden; columna++){
            posAux[1] = columna;
            if(obtenerRotacion(posAux, matriz, orden, estado) == -1) resultado += " ";
            else resultado += to_string(obtenerRotacion(posAux, matriz, orden, estado));
            resultado += " ";
        }
        resultado += "\n";
    }
    delete [] matriz;
    return resultado;
}

string **generarOpciones(int numMatrices){
    string **resultado = new string*[2];
    string aux = "";
    resultado[0] = new string[numMatrices + 2];
    resultado[1] = new string[1];
    for(int cont = 0; cont < numMatrices + 2; cont++){
        resultado[0][cont] = to_string(cont + 1);
        aux += to_string(cont + 1) + ". ";
        if(cont + 1 != numMatrices + 1 && cont + 1 != numMatrices + 2) aux += "Visualizar Estructura " + to_string(cont + 1);
        else if(cont + 1 == numMatrices + 1) aux += "Volver a iniciar el programa";
        else aux += "Salir del programa\n";
        aux += "\n";
    }
    resultado[1][0] = aux;
    return resultado;
}
