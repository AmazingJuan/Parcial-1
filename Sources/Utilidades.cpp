#import "../Headers/Utilidades.h"


/**
 * Breve descripción de la función genRandom.
 *
 * Genera un numero aleatorio entre un numero menor y un numero mayor, el numero mayor es considerado en la generacion del numero.
 *
 * @param menor Numero que servira como limite inferior para la generacion del numero aleatorio.
 * @param mayor Numero que servira como limite superior para la generacion del numero aleatorio.
 * @return Un entero aleatorio comprendido entre el numero menor y el numero mayor, incluyendolos.
 */


int genRandom(int menor, int mayor){ //Hicimos uso de un codigo de internet localizado acá: https://learn.microsoft.com/en-us/cpp/standard-library/random?view=msvc-170. No usamos la funcion para numeros aleatorios que se recomendo en la practica 1 o 2 ya que estos numeros eran pseudo aleatorios.
    random_device rd; //Inicializa un dato de tipo random_device, que tiene como función generar una semilla aleatoria para el algoritmo de generacion de numeros.
    mt19937 gen(rd()); //Se crea una instancia de la clase mt19937, donde el parametro del constructor es rd(), es decir la semilla aleatoria con la cual se generará el numero.
    uniform_int_distribution<> dist(menor, mayor); //Se crea una instancia de la clase uniform_int_Distribution, esta crea una distribución uniforme de numeros enteros entre el numero menor y el mayor.
    return dist(gen); //Finalmente se retorna un numero aleatorio que pertenece a la distribución.
}

/**
 * Breve descripción de la función limpiarPantalla.
 *
 * Imprime 50 saltos de linea, simulando que se elimino lo que habia previamente en la pantalla.
 *
 * @return Ninguno, solo son impresiones.
 */

void limpiarPantalla(){
    for(int cont = 0; cont < 50; cont++) cout << "\n";
}

/**
 * Breve descripción de la función stringInArray.
 *
 * Verifica si una cadena es un elemento de un arreglo.
 *
 * @param cadena Cadena dada.
 * @param arreglo Arreglo en el cual debe comprobarse si existe una cadena dada o no.
 * @param lenArreglo Tamaño del arreglo dado.
 * @return Booleano que indica si la cadena dada es un elemento del arreglo especificado.
 */

bool stringInArray(string cadena, string* arreglo, int lenArreglo){
    for(int cont = 0; cont < lenArreglo; cont ++) if(cadena == arreglo[cont]) return true;
    return false;
}

/**
 * Breve descripción de la función obtenerMensaje.
 *
 * Permite obtener un mensaje segun un parametro dado, los mensajes son completamente parte de la seccion de experiencia de usuario.
 *
 * @param parametro Numero que indica que mensaje se desea obtener.
 * @return String que contiene el mensaje deseado.
 */

string obtenerMensaje(int parametro){
    switch (parametro){
        case 1: //Mensaje de bienvenida
            return "  ____    _                                         _       _         \n |  _ \\  (_)                                       (_)     | |        \n | |_) |  _    ___   _ __   __   __   ___   _ __    _    __| |   ___  \n |  _ <  | |  / _ \\ | '_ \\  \\ \\ / /  / _ \\ | '_ \\  | |  / _` |  / _ \\ \n | |_) | | | |  __/ | | | |  \\ V /  |  __/ | | | | | | | (_| | | (_) |\n |____/  |_|  \\___| |_| |_|   \\_/    \\___| |_| |_| |_|  \\__,_|  \\___/ \n\nBienvenido al Desafio 1, en unos momentos podra ingresar la regla para generar el candado...";
        case 2: //Mensaje para que el usuario ingrese la fila
            return "  ______   _   _         \n |  ____| (_) | |        \n | |__     _  | |   __ _ \n |  __|   | | | |  / _` |\n | |      | | | | | (_| |\n |_|      |_| |_|  \\__,_|\n                         \n";
        case 3: //Mensaje para que el usuario ingrese la columna
            return "   _____           _                                     \n  / ____|         | |                                    \n | |        ___   | |  _   _   _ __ ___    _ __     __ _ \n | |       / _ \\  | | | | | | | '_ ` _ \\  | '_ \\   / _` |\n | |____  | (_) | | | | |_| | | | | | | | | | | | | (_| |\n  \\_____|  \\___/  |_|  \\__,_| |_| |_| |_| |_| |_|  \\__,_|\n                                                         \n";
        case 4: //Mensaje para que el usuario ingrese el criterio deseado (contiene las opciones).
            return "   _____          _   _                   _         \n  / ____|        (_) | |                 (_)        \n | |       _ __   _  | |_    ___   _ __   _    ___  \n | |      | '__| | | | __|  / _ \\ | '__| | |  / _ \\ \n | |____  | |    | | | |_  |  __/ | |    | | | (_) |\n  \\_____| |_|    |_|  \\__|  \\___| |_|    |_|  \\___/ \n                                                    \nHe aqui los criterios de comparacion disponibles para las estructuras ";
        case 5: //Mensaje de error.
            return "  ______                              \n |  ____|                             \n | |__     _ __   _ __    ___    _ __ \n |  __|   | '__| | '__|  / _ \\  | '__|\n | |____  | |    | |    | (_) | | |   \n |______| |_|    |_|     \\___/  |_|   \n                                      \n";
        case 6: //Indica al usuario que se pudo encontrar una combinacion que cumpliera la regla que ingreso.
            return "  ______          _   _          _       _               _              \n |  ____|        | | (_)        (_)     | |             | |             \n | |__      ___  | |  _    ___   _    __| |   __ _    __| |   ___   ___ \n |  __|    / _ \\ | | | |  / __| | |  / _` |  / _` |  / _` |  / _ \\ / __|\n | |      |  __/ | | | | | (__  | | | (_| | | (_| | | (_| | |  __/ \\__ \\\n |_|       \\___| |_| |_|  \\___| |_|  \\__,_|  \\__,_|  \\__,_|  \\___| |___/\n                                                                       \nFelicidades, hemos encontrado una combinacion de candado para la regla que usted especifico, fijese en las opciones que le brindamos:\n\n";
        case 7: //Mensaje que contiene la palabra "Visualizar matriz".
            return " __      __  _                         _   _                     _                \n \\ \\    / / (_)                       | | (_)                   | |               \n  \\ \\  / /   _   ___   _   _    __ _  | |  _   ____   __ _    __| |   ___    _ __ \n   \\ \\/ /   | | / __| | | | |  / _` | | | | | |_  /  / _` |  / _` |  / _ \\  | '__|\n    \\  /    | | \\__ \\ | |_| | | (_| | | | | |  / /  | (_| | | (_| | | (_) | | |   \n     \\/     |_| |___/  \\__,_|  \\__,_| |_| |_| /___|  \\__,_|  \\__,_|  \\___/  |_|   \n                                                                                   \nHe aqui la informacion de la Estructura ";
        case 8: //Mensaje de despedida.
            return "  _____                                    _   _       _               \n |  __ \\                                  | | (_)     | |              \n | |  | |   ___   ___   _ __     ___    __| |  _    __| |   __ _       \n | |  | |  / _ \\ / __| | '_ \\   / _ \\  / _` | | |  / _` |  / _` |      \n | |__| | |  __/ \\__ \\ | |_) | |  __/ | (_| | | | | (_| | | (_| |      \n |_____/   \\___| |___/ | .__/   \\___|  \\__,_| |_|  \\__,_|  \\__,_|      \n                       | |                                            \n                       |_|                                           \nMuchas gracias por usar nuestro programa, vuelva pronto...";
        default:
            return "";
    }
}

/**
 * Breve descripción de la función congelarPantalla.
 *
 * Permite congelar la pantalla por un tiempo determinado.
 *
 * @param segundos Numero que indica cuantos segundos se desea congelar la pantalla.
 * @return Ninguno.
 */

void congelarPantalla(int segundos){ //Se usó el ejemplo dado en la siguiente pagina: https://en.cppreference.com/w/cpp/thread/sleep_for.
    this_thread::sleep_for(segundos * 1000ms);
}

/**
 * Breve descripción de la función stringMatriz.
 *
 * Permite obtener la matriz de un orden especifico en un estado dado.
 *
 * @param orden Entero que nos habla del orden de la matriz.
 * @param estado Estado de la matriz que se quiere obtener.
 * @return String que representa la matriz en el estado dado, se rota si es necesario.
 */

string stringMatriz(int orden, int estado){
    int **matriz = crearMatriz(orden); //Se crea la matriz en estado neutral.
    string estadoAux; //String auxiliar para almacenar el estado de la matriz.
    int *posAux = new int[2]; //Se crea un arreglo de enteros para poder ejecutar la funcion obtenerRotacion.
    if(estado == 0) estadoAux = "Neutral"; //Si el estado como entero vale 0, entonces como string va a valer neutral, de otra manera simplemente se pone el numero de 1 - 3.
    else estadoAux = to_string(estado);

    string resultado = "Orden: " + to_string(orden) + "\nEstado: " + estadoAux + "\n\nMatriz solicitada:\n\n"; //Se inicializa un string donde se incluya el orden de la matriz y su estado
    //Por ultimo se añade la matriz en el estado dado al string resultado mediante el ciclo for de las lineas 114 - 123.
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

    //Se libera memoria y posteriormente se retorna el string deseado.
    delete [] matriz;
    delete [] posAux;
    return resultado;
}

/**
 * Breve descripción de la función generarOpciones.
 *
 * Genera el string que contiene las opciones de visualizacion de matrices para cuando se haya encontrado la conbinación de candado.
 *
 * @param numMatrices Entero que nos habla del numero de matrices que es posible visualizar.
 * @return String que contiene las opciones deseadas.
 */

string **generarOpciones(int numMatrices){
    string **resultado = new string*[2]; //Se hace una matriz de strings.
    string aux = ""; //Se define un string auxiliar
    resultado[0] = new string[numMatrices + 2]; //Se crea en la posición 0 un arreglo de strings de tamaño numMatrices + 2, donde se incluyen el numero de las opciones de las matrices, y dos mas para salir del programa o volver a inciarlo.
    resultado[1] = new string[1]; //Se crea un string que contendrá el texto que el usuario debe visulizar.
    for(int cont = 0; cont < numMatrices + 2; cont++){ //Ciclo for que va agregando al arreglo de strings las opciones pertinentes, tal como el texto que se quiere mostrar.
        resultado[0][cont] = to_string(cont + 1);
        aux += to_string(cont + 1) + ". ";
        if(cont + 1 != numMatrices + 1 && cont + 1 != numMatrices + 2) aux += "Visualizar Estructura " + to_string(cont + 1);
        else if(cont + 1 == numMatrices + 1) aux += "Volver a iniciar el programa";
        else aux += "Salir del programa\n";
        aux += "\n";
    }
    resultado[1][0] = aux; //Se le asigna a la posicion del texto el string auxiliar que contenia el texto deseado.
    return resultado;
}
