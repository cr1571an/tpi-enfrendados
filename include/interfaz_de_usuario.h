#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
using namespace std;
#include "interfaz_de_usuario.h"

void portada();

void menu_principal();

void menu_juego();

void enter();

void esperar_1_segundos();

string centrar(string texto, int ancho);

void mensaje_inicio_juego();

void mensaje_para_las_rondas(int ronda, string nombres_jugadores[], int jugador );

void mensaje_para_tirar_dado_6_cara( string nombres_jugadores[], int jugador );

void mensaje_empate();

void mensaje_dados_stock(int dodos_stock[], int jugador);

void mensaje_dados_seleccionados();

void mensaje_gano_la_partida(int puntaje, int suma);

void mensaje_objetivo_cumplido(string nombres_jugadores[], int jugador, int cant_dados_stock[],int cantidad_dados_seleccionados, int suma_dados_seleccionados, int puntaje);

void mensaje_objetivo_no_cumplido( int cant_dados_stock[], int jugador,  int ronda, string nombre_jugador[], int suma);

void intercambiar_si_es_necesario(int &dado1, int &dado2, string &nombre1, string &nombre2);

void mostrar_dados_12(int dado1, int dado2);

void mostrar_solo_un_dado(int numero);

void mostrar_dados_horizontal(int v[], int dodos_stock, bool mostra_posicion);

void limpiar_pantalla();

void mensaje_objetivo_no_cumplido_mas_stock_max( int cant_dados_stock[], int jugador,  int ronda, string nombre_jugador[], int suma);

void credito();

#endif