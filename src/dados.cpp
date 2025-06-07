#include "dados.h"
#include <cstdlib>
#include <ctime>
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

void seleccionar_dados(int dados[], int dados_seleccionados[], int cantidad){
    int seleccionado = 0;
    int i = 0;
    cout << "Selecciona un dado en base a su posicion: ";
    cin >> seleccionado;
    while (seleccionado != 0 && i < cantidad) {
        dados_seleccionados[i] = dados[seleccionado-1];
        i++;
        cout << "Selecciona un dado en base a su posicion: ";
        cin >> seleccionado;
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