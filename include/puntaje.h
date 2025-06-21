#ifndef PUNTAJE_H
#define PUNTAJE_H

#include "puntaje.h"
#include <string>
using namespace std;

void penalizar_jugador(int jugador,int cant_dados_stock[], int ronda, string nombres_jugadores[], int suma);

void transferir_dados(int jugador, int cant_dados[],int cantidad);

int calcular_puntaje(int cantidad, int suma);
#endif