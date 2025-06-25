#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <string>
using namespace std;
#include "estadistica.h"

void guardar_puntaje_por_ronda(int jugador, int ronda, int puntaje, int puntajes[]);

void anunciar_ganador_o_empate(int resultado_final, string nombres_jugadores[]);

void mostrar_resumen(int puntajes_por_rondas_jugadores[], string nombres_jugadores[], int ronda, int puntaje_acumulado_por_jugadores[]);

void guardar_resultado(string nombres_jugadores[], int puntaje_acumulado_por_jugadores[],int resultado_final, string ranking_jugadores[], int ranking_puntajes[], int longitud_ranking);

int obtener_resultado_final(int puntaje_jugadores[]);

#endif
