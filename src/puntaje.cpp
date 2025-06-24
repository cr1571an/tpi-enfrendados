#include "puntaje.h"
#include "interfaz_de_usuario.h"
#include <string>
using namespace std;

void penalizar_jugador(int jugador, int cant_dados_stock[], int ronda, string nombres_jugadores[], int suma) {
    int oponente;
    if (jugador == 0)
        oponente = 1;
    else
        oponente = 0;
    if (cant_dados_stock[oponente]>1) {
        cant_dados_stock[oponente]--;
        cant_dados_stock[jugador]++;
        mensaje_objetivo_no_cumplido( cant_dados_stock, jugador, ronda, nombres_jugadores, suma);
    }
    else {
        mensaje_objetivo_no_cumplido_mas_stock_max(cant_dados_stock, jugador, ronda, nombres_jugadores, suma);
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