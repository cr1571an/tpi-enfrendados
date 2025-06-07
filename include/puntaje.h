#ifndef PUNTAJE_H
#define PUNTAJE_H

#include "puntaje.h"

void penalizar_jugador(int jugador, int cant_dados[]);

void transferir_dados(int jugador, int cant_dados[],int cantidad);

int calcular_puntaje(int cantidad, int suma);
#endif