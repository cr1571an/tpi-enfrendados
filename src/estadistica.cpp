#include <iostream>
#include <string>
#include "interfaz_de_usuario.h"
using namespace std;

void guardar_puntaje_por_ronda(int num_jugadores, int ronda, int puntaje, int puntajes_por_rondas_jugadores[], string nombres_jugadores[]) {
    int indice = (ronda - 1) * 2 + num_jugadores;
    puntajes_por_rondas_jugadores[indice] = puntaje;
}


void mostrar_estadistica( int puntajes_por_rondas_jugadores[], string nombres_jugadores[],int num_jugadores, int num_rondas) {
    for (int jugador = 0; jugador < num_jugadores; ++jugador) {
        int total = 0;
        cout << " Resultados de " << nombres_jugadores[jugador] << endl;
        for (int ronda = 1; ronda <= num_rondas; ++ronda) {
            int indice = (ronda - 1) * num_jugadores + jugador;
            int puntos = puntajes_por_rondas_jugadores[indice];
            total += puntos;
            cout << "  Ronda " << ronda << ": " << puntos << " puntos"<<endl;
        }
        cout << "  Total acumulado: " << total << " puntos"<<endl<<endl;
    }
}

void mostrar_estadistica(int puntajes_por_rondas_jugadores[], string nombres_jugadores[], int ronda, int puntaje_acumulado_por_jugadores[]) {
    int ancho = 56;
    cout << "   ╔════════════════════════════════════════════════════════╗" << endl;
    cout << "   ║" << centrar("ESTADISTICA DE LA PARTIDA!", ancho) << "║" << endl;
    cout << "   ╠════════════════════════════════════════════════════════╣" << endl;
    for (int i = 0; i < ronda; i++) {
        cout << "   ║" << centrar("RONDA " + to_string(i + 1), ancho) << "║" << endl;
        cout << "   ║" << centrar(nombres_jugadores[0] + " OBTUVO " + to_string(puntajes_por_rondas_jugadores[i * 2]), ancho) << "║" << endl;
        cout << "   ║" << centrar(nombres_jugadores[1] + " OBTUVO " + to_string(puntajes_por_rondas_jugadores[i * 2 + 1]), ancho) << "║" << endl;
        cout << "   ╠════════════════════════════════════════════════════════╣" << endl;
    }
    if (ronda == 3) {
        cout << "   ║" << centrar("PUNTAJE TOTAL DE LA PARTIDA!", ancho) << "║" << endl;
        cout << "   ╠════════════════════════════════════════════════════════╣" << endl;
        cout << "   ║" << centrar(nombres_jugadores[0] + " OBTUVO UN TOTAL DE " + to_string(puntaje_acumulado_por_jugadores[0]), ancho) << "║" << endl;
        cout << "   ║" << centrar(nombres_jugadores[1] + " OBTUVO UN TOTAL DE " + to_string(puntaje_acumulado_por_jugadores[1]), ancho) << "║" << endl;
        cout << "   ╠════════════════════════════════════════════════════════╣" << endl;
        cout << "   ║" << centrar("PRESIONE ENTER PARA VOLVER AL MENU PRINCIPAL", ancho) << "║" << endl;
        cout << "   ╚════════════════════════════════════════════════════════╝" << endl;
        enter();
    }
}
