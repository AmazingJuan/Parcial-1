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
