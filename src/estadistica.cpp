#include <iostream>
#include <string>
#include "interfaz_de_usuario.h"
using namespace std;

void guardar_puntaje_por_ronda(int num_jugadores, int ronda, int puntaje, int puntajes_por_rondas_jugadores[]) {
    int indice = (ronda - 1) * 2 + num_jugadores;
    puntajes_por_rondas_jugadores[indice] = puntaje;
}


void anunciar_ganador_o_empate(int puntaje_acumulado_por_jugadores[], string nombres_jugadores[]) {

    if (puntaje_acumulado_por_jugadores[0] != puntaje_acumulado_por_jugadores[1]) {
        int indice_ganador;
        if (puntaje_acumulado_por_jugadores[0] > puntaje_acumulado_por_jugadores[1]) {
            indice_ganador = 0;
        } else {
            indice_ganador = 1;
        }
        cout << "   ╔════════════════════════════════════════════════════════════════════════╗" << endl;
        cout << "   ║" << centrar("¡FELICIDADES " + nombres_jugadores[indice_ganador] + ", GANASTE!", 73) << "║" << endl;
        cout << "   ╠════════════════════════════════════════════════════════════════════════╝" << endl;
        cout << "   ║ ENTER PARA VER EL RESUMEN DE LA PARTIDA  ║" << endl;
        cout << "   ╚══════════════════════════════════════════╝";enter();
        cout << endl;
    } else {
        cout << "   ╔════════════════════════════════════════════════════════════════════════╗" << endl;
        cout << "   ║" << centrar("¡HUBO EMPATE TECNICO!", 73) << "║" << endl;
        cout << "   ╠════════════════════════════════════════════════════════════════════════╝" << endl;
        cout << "   ║ ENTER PARA VER EL RESUMEN DE LA PARTIDA  ║" << endl;
        cout << "   ╚══════════════════════════════════════════╝" << endl;
        enter();
        cout << endl;
    }
}



void mostrar_resumen(int puntajes_por_rondas_jugadores[], string nombres_jugadores[], int ronda, int puntaje_acumulado_por_jugadores[]) {
    int ancho = 56;
    cout << "   ╔════════════════════════════════════════════════════════╗" << endl;
    cout << "   ║" << centrar("RESUMER DE LA PARTIDA!", ancho) << "║" << endl;
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
        cout << "   ╚════════════════════════════════════════════════════════╝";enter();
        cout <<endl;
    }
}

void guardar_ganador(string nombres_jugadores[], int puntaje_acumulado_por_jugadores[], string ranking_jugadores[], int ranking_puntajes[]){
    if (puntaje_acumulado_por_jugadores[0] > puntaje_acumulado_por_jugadores[1])
        agregar_ganador(ranking_jugadores, ranking_puntajes, nombres_jugadores[0], puntaje_acumulado_por_jugadores[0]);
    else if (puntaje_acumulado_por_jugadores[1] > puntaje_acumulado_por_jugadores[0])
        agregar_ganador(ranking_jugadores, ranking_puntajes, nombres_jugadores[1], puntaje_acumulado_por_jugadores[1]);
    else{
        agregar_ganador(ranking_jugadores, ranking_puntajes, nombres_jugadores[0], puntaje_acumulado_por_jugadores[0]);
        agregar_ganador(ranking_jugadores, ranking_puntajes, nombres_jugadores[1], puntaje_acumulado_por_jugadores[1]);
    }    
}

void agregar_ganador(string ranking_jugadores[], int ranking_puntajes[], string nombre_jugador, int puntaje) {
    //al agregar un ganador, si el ranking esta lleno, se elimina el ultimo jugador y se agrega el nuevo.
    // hay que agregar ordenado por mayor puntaje.
}
