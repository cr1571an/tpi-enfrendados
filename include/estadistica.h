#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <string>
using namespace std;
#include "estadistica.h"

void guardar_puntaje_por_ronda(int jugador, int ronda, int puntaje, int puntajes[], string nombres_jugadores[]);

void mostrar_estadistica(int puntajes_por_rondas_jugadores[], string nombres_jugadores[], int ronda, int puntaje_acumulado_por_jugadores[]);

#endif //ESTADISTICA_H
