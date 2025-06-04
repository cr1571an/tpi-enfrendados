#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
using namespace std;
#include "funciones.h"

// Definiciones de las funciones

// Muestra el nombre del juego.
void portada();
// Muestra el menu del juego.
void menu();
//La función pide y valida una opción del menú entre 0 y 3, y devuelve la opción seleccionada.
int opcion_seleccionada();
// Esta funcion genera y devuelve un numero aleatorio entre 1 y 6.
int dado_de_6_cada();
// Esta funcion genera y devuelve un numero aleatorio entre 1 y 12.
int tirar_dados_objetivo();
// Esta funcion muestra un mensaje al usuario que tiene que presionar Enter para continuar.
void enter();
// Esta funcion pausa la ejecucion durante 1 segundo.
void esperar_1_segundos();
// Esta funcion compara los valores de los jugadores y anuncia quien comienza, o indica empate si ambos sacaron el mismo numero.
void anuncio_Jugador(int jugador1, int jugador2, string nombre1, string nombre2);
// Esta funcion compara dos numero y su nombre asociados y si el segundo numero es mayor, intercambia sus nombres para que siempre el primero sea el mayor.
void intercambiar_si_es_necesario(int &dado1, int &dado2, string &nombre1, string &nombre2);
// Esta funcion simula 6 lazamiento de dado de 6 caras, completa el stock según los resultados obtenidos.
void simular_tiradas_dado_6(int stock[6]);
// Esta funcion muestra todos los dados disponibles en el stock, repitiendo cada valor según su cantidad.
void mostrar_dados_12(int dado1, int dado2);
//Esta funcion muestra una representacion un dado segun el numero. Entre 1 y 6.
void mostrar_dado(int numero);

#endif //FUNCIONES_H