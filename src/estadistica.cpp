#include <iostream>
#include <string>
#include "interfaz_de_usuario.h"
using namespace std;

void guardar_puntaje_por_ronda(int num_jugadores, int ronda, int puntaje, int puntajes_por_rondas_jugadores[]) {
    int indice = (ronda - 1) * 2 + num_jugadores;
    puntajes_por_rondas_jugadores[indice] = puntaje;
}


void anunciar_ganador_o_empate(int resultado_final, string nombres_jugadores[]) {

    if (resultado_final != -1) {
        cout << "   ╔════════════════════════════════════════════════════════════════════════╗" << endl;
        cout << "   ║" << centrar("¡FELICIDADES " + nombres_jugadores[resultado_final] + ", GANASTE!", 73) << "║" << endl;
        cout << "   ╠════════════════════════════════════════════════════════════════════════╝" << endl;
        cout << "   ║ ENTER PARA VER EL RESUMEN DE LA PARTIDA  ║" << endl;
        cout << "   ╚══════════════════════════════════════════╝";enter();
    } else {
        cout << "   ╔════════════════════════════════════════════════════════════════════════╗" << endl;
        cout << "   ║" << centrar("¡HUBO EMPATE TECNICO!", 73) << "║" << endl;
        cout << "   ╠════════════════════════════════════════════════════════════════════════╝" << endl;
        cout << "   ║ ENTER PARA VER EL RESUMEN DE LA PARTIDA  ║" << endl;
        cout << "   ╚══════════════════════════════════════════╝";enter();
    }
}


void mostrar_resumen(int puntajes_por_rondas_jugadores[], string nombres_jugadores[], int ronda, int puntaje_acumulado_por_jugadores[]) {
    int ancho = 56;
    cout << "   ╔════════════════════════════════════════════════════════╗" << endl;
    cout << "   ║" << centrar("RESUMER DE LA PARTIDA!", ancho) << "║" << endl;
    cout << "   ╠════════════════════════════════════════════════════════╣" << endl;
    for (int i = 0; i < ronda; i++) {
        cout << "   ║" << centrar("RONDA " + to_string(i + 1), ancho) << "║" << endl;
        cout << "   ║" << centrar(nombres_jugadores[0] + " OBTUVO " + to_string(puntajes_por_rondas_jugadores[i * 2])+" PTS", ancho) << "║" << endl;
        cout << "   ║" << centrar(nombres_jugadores[1] + " OBTUVO " + to_string(puntajes_por_rondas_jugadores[i * 2 + 1])+" PTS", ancho) << "║" << endl;
        cout << "   ╠════════════════════════════════════════════════════════╣" << endl;
    }
    if (ronda == 3) {
        cout << "   ║" << centrar("PUNTAJE TOTAL DE LA PARTIDA!", ancho) << "║" << endl;
        cout << "   ╠════════════════════════════════════════════════════════╣" << endl;
        cout << "   ║" << centrar(nombres_jugadores[0] + " OBTUVO UN TOTAL DE " + to_string(puntaje_acumulado_por_jugadores[0])+" PTS", ancho) << "║" << endl;
        cout << "   ║" << centrar(nombres_jugadores[1] + " OBTUVO UN TOTAL DE " + to_string(puntaje_acumulado_por_jugadores[1])+" PTS", ancho) << "║" << endl;
        cout << "   ╠════════════════════════════════════════════════════════╣" << endl;
        cout << "   ║" << centrar("PRESIONE ENTER PARA VOLVER AL MENU PRINCIPAL", ancho) << "║" << endl;
        cout << "   ╚════════════════════════════════════════════════════════╝";enter();
    }
}


void agregar_ganador(string ranking_jugadores[], int ranking_puntajes[], string nombre_jugador, int puntaje, int longitud_ranking) {
    int i = 0;
    while (i < longitud_ranking && ranking_puntajes[i] > puntaje) {
        i++;
    }
    if (i < longitud_ranking) {
        int j = longitud_ranking - 1;
        for (j; j > i; j--) {
            ranking_puntajes[j] = ranking_puntajes[j - 1];
            ranking_jugadores[j] = ranking_jugadores[j - 1];
        }
        ranking_puntajes[i] = puntaje;
        ranking_jugadores[i] = nombre_jugador;
    }
}


int obtener_resultado_final(int puntaje_acumulado_por_jugadores[]) {
    if (puntaje_acumulado_por_jugadores[0] > puntaje_acumulado_por_jugadores[1])
        return 0;
    else if (puntaje_acumulado_por_jugadores[1] > puntaje_acumulado_por_jugadores[0])
        return 1;
    return -1;
}


void guardar_resultado(string nombres_jugadores[], int puntaje_acumulado_por_jugadores[],int resultado_final, string ranking_jugadores[], int ranking_puntajes[], int longitud_ranking){
    if (resultado_final == 0)
        agregar_ganador(ranking_jugadores, ranking_puntajes, nombres_jugadores[0], puntaje_acumulado_por_jugadores[0], longitud_ranking);
    else if (resultado_final == 1)
        agregar_ganador(ranking_jugadores, ranking_puntajes, nombres_jugadores[1], puntaje_acumulado_por_jugadores[1], longitud_ranking);
    else{
        agregar_ganador(ranking_jugadores, ranking_puntajes, nombres_jugadores[0], puntaje_acumulado_por_jugadores[0], longitud_ranking);
        agregar_ganador(ranking_jugadores, ranking_puntajes, nombres_jugadores[1], puntaje_acumulado_por_jugadores[1], longitud_ranking);
    }    
}
