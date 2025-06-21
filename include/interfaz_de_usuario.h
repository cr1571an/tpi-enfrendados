#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
using namespace std;
#include "interfaz_de_usuario.h"

/// Definiciones de las funciones
// Muestra el nombre del juego.
void portada();
// Muestra el menu principal.
void menu_principal();
// Muestra el menu del juego.
void menu_juego();
//La función pide y valida una opción del menú entre 0 y 3, y devuelve la opción seleccionada.
int opcion_seleccionada();
// Esta funcion muestra un mensaje al usuario que tiene que presionar Enter para continuar.
void enter();
// Esta funcion pausa la ejecucion durante 1 segundo.
void esperar_1_segundos();
// Esta funcion centra un texto en la pantalla segun el ancho.
string centrar(string texto, int ancho);
// Muestra un mensaje diciendo como se elige el jugador que empieza la ronda.
void mensaje_inicio_juego();
// Muestra un mensaje de las rondas con el nombre del jugador.
void mensaje_para_las_rondas(int ronda, string nombres_jugadores[], int jugador );
// Muestra un mensaje de que el jugador debe presionar enter para lanzar el dado de 6 cara para ver que en empieza la ronda.
void mensaje_para_tirar_dado_6_cara( string nombres_jugadores[], int jugador );
// Muestra un mensaje de empate si es que lo hay.
void mensaje_empate();
// Muestra un mensaje al jugador de que dice "los dados disponible de tu stock".
void mensaje_dados_stock(int dodos_stock[], int jugador);
// Muestra un mensaje al jugador de que dice "los dados seleccionados".
void mensaje_dados_seleccionados();
// Muestra un mensaje si el jugador gana la partida.
void mensaje_gano_la_partida(int puntaje, int suma);
// Muestra un mensaje si el jugador cumple con el objetivo.
void mensaje_objetivo_cumplido(string nombres_jugadores[], int jugador, int cant_dados_stock[],int cantidad_dados_seleccionados, int suma_dados_seleccionados, int puntaje);
// Muestra un mensaje si el jugador no cumple con el objetivo segun la ronda o la cantidad de dados que tiene en el stock el oponente.
void mensaje_objetivo_no_cumplido( int cant_dados_stock[], int jugador,  int ronda, string nombre_jugador[], int suma);
// Esta funcion compara dos numeroo y su nombre asociados y si el segundo numero es mayor, intercambia sus nombres para que siempre el primero sea el mayor.
void intercambiar_si_es_necesario(int &dado1, int &dado2, string &nombre1, string &nombre2);
// Esta funcion muestra todos los dados disponibles en el stock, repitiendo cada valor según su cantidad.
void mostrar_dados_12(int dado1, int dado2);
//Esta funcion muestra solo un dado segun el numero. Entre 1 y 6.
void mostrar_solo_un_dado(int numero);
// Muestra los dados seleccionados.
void mostrar_dados_horizontal(int v[], int dodos_stock, int cant_dados);
// Que muestra los dados del stock o los dados seleccionados para el objetivo.
void limpiar_pantalla();
void mensaje_objetivo_no_cumplido_mas_stock_max( int cant_dados_stock[], int jugador,  int ronda, string nombre_jugador[], int suma);

#endif //FUNCIONES_H