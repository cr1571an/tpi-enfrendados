#include "dados.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int tirar_dado(int caras) {
    return rand() % caras + 1;
}


void tirar_dados(int dados[], int cantidad, int caras) {
    for (int i = 0; i < cantidad; ++i) {
        dados[i] = tirar_dado(caras);
    }
}


void seleccionar_dados(int dados[], int dados_seleccionados[], int cantidad) {
    int seleccionado;
    int i = 0;
    bool posiciones_usadas[11] = {false};
    cout << "Selecciona un dado en base a su posicion (0 para terminar): ";
    cin >> seleccionado;
    while (seleccionado != 0 && i < cantidad) {
        if (seleccionado < 1 || seleccionado > cantidad) {
            cout << "Posicion invalida. Intenta de nuevo: ";
            cin >> seleccionado;
        }
        // Si ya fue usada la posicion
        else if (posiciones_usadas[seleccionado - 1]) {
            cout << "No se puede repetir de dado. Por favor intenta de nuevo: ";
            cin >> seleccionado;
        }
        else {
            // Se guarda el valor del dado y se marcar la posicion como usada
            dados_seleccionados[seleccionado - 1] = dados[seleccionado - 1];
            posiciones_usadas[seleccionado - 1] = true;
            i++;
            cout << "Selecciona un dado en base a su posicion (0 para terminar): ";
            cin >> seleccionado;
        }
    }
}


int sumar_dados(int dados[], int cantidad) {
    int suma = 0;
    for (int i = 0; i < cantidad; ++i) {
        suma += dados[i];
    }
    return suma;
}


int contador_dados(int dados[], int tamanio) {
    int contador = 0;
    for (int i = 0; i < tamanio; ++i) {
        if (dados[i] != 0) {
            contador++;
        }
    }
    return contador;
}