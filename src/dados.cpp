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

void dados_stock(int dado_stock_jugadores[], int elemento) {
    for (int i = 0; i < elemento; i++) {
        dado_stock_jugadores[i] = tirar_dado(6);
    }
}

void mostrar_stock(int dado_stock_jugadores[], int elemento) {
    cout << "Dados en stock: ";
    for (int i = 0; i < elemento; i++) {
        if (dado_stock_jugadores[i] != 0) {
            cout << dado_stock_jugadores[i] << " ";
        }
    }
    cout << endl;
}


int ingresar_combinacion(int combinacion[], int &cantidad) {
    int numero;
    cantidad = 0;
    cout << "Ingresa combinacion (finalizar combinacion con 0):\n";
    for (int i = 0; i < 12; ++i) {
        cin >> numero;

        if (numero == 0) {
            break;
        }
        combinacion[i] = numero;
        cantidad++;
    }
    return cantidad;
}

int vericar_si_se_cumplio_el_objetivo(int combinacion[], int &objetivo) {
    for (int i = 0; i < 12; ++i) {
        if (combinacion[i]>0) {
            objetivo -= combinacion[i];
        }
    }
    return objetivo;
}


int validar_numero_ingresado(int combinacion[], int numero) {
    int contador = 0;
    for (int i = 0; i < 12 && combinacion[i] != 0; ++i) {
        if (combinacion[i] == numero) {
            contador++;
        }
    }
    return contador;
}


bool verificar_combinacion(int dado_stock_jugadores[], int combinacion[]) {
    for (int i = 0; i < 12 && combinacion[i] != 0; ++i) {
        int num = combinacion[i];
        int cuenta_conbinacion = validar_numero_ingresado(combinacion, num);
        int cuenta_dado_stock_jugadores = validar_numero_ingresado(dado_stock_jugadores, num);

        if (cuenta_conbinacion > cuenta_dado_stock_jugadores) {
            return false;
        }
        for (; i + 1 < 12 && combinacion[i + 1] == num; ++i);
    }
    return true;
}


void mensaje_para_la_combinacion(bool es_valida, int contador, string nombre_jugador[], int indice_del_jugador, int objetivo) {
    if (es_valida && objetivo==0 ) {
        cout << "La combinacion fue valida. Se le sumaran " << contador << " dados mas a " << nombre_jugador[indice_del_jugador] << "." << endl;
    } else {
        cout << "La combinacian fue invalida. " << nombre_jugador[indice_del_jugador] << " te dara un dado de su stock." << endl;
    }
}

