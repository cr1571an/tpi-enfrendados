#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <string>
using namespace std;
#include "estadistica.h"

void guardar_puntaje_por_ronda(int jugador, int ronda, int puntaje, int puntajes[]);

void mostrar_resumen_partida(int puntajes_por_rondas_jugadores[], string nombres_jugadores[], int ronda, int puntaje_acumulado_por_jugadores[]);

void guardar_ganador(string nombres_jugadores[], int puntaje_acumulado_por_jugadores[],string ranking_jugadores[], int ranking_puntajes[]);

void agregar_ganador(string ranking_jugadores[], int ranking_puntajes[], string nombre_jugador, int puntaje);
#endif
