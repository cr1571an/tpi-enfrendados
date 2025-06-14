#include "puntaje.h"

void penalizar_jugador(int jugador, int cant_dados[]) {
    int oponente = jugador ^ 1 ;

    if (cant_dados[oponente] > 1) {
        cant_dados[oponente]--;
        cant_dados[jugador]++;
    }
}

void transferir_dados(int jugador, int cant_dados[],int cantidad){
    if (jugador == 0)
        cant_dados[jugador + 1] += cantidad;
    else 
        cant_dados[jugador - 1] += cantidad;
    cant_dados[jugador] -= cantidad;    
}

int calcular_puntaje(int cantidad, int suma){
    return cantidad * suma;
}