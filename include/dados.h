#ifndef DADOS_H
#define DADOS_H
#include <iostream>
using namespace std;

#include "dados.h"

// Genera un numero aleatorio entre 1 y la cantidad de caras del dado que se le pasa como parametro.
int tirar_dado(int caras);

// Llena un vector con resultados de tirar varios dados segun la cantidad y caras del dado.
void tirar_dados(int dados[], int cantidad, int caras);

// Asigna valores aleatorios entre 1 y 6 a un arreglo que representa los dados en stock de un jugador.
void dados_stock(int stock[], int elemento);

// Muestra por consola los valores de los dados que no han sido usados (distintos de 0).
void mostrar_stock(int stock[], int elemento);

// Permite al usuario ingresar una combinacion para intentar alcanzar el objetivo. Finaliza la carga al vector cuando se ingresa un 0.
int ingresar_combinacion(int combinacion[], int &cantidad);

// Resta los valores de la combinacion al numero objetivo. Sirve para verificar si la suma de la combinacion cumple el objetivo.
int vericar_si_se_cumplio_el_objetivo(int combinacion[], int &objetivo);

// Cuenta cuantas veces aparece un numero especifico en una combinacion.
int validar_numero_ingresado(int conbinacion[], int numero);

// Verifica si la combinacion ingresada por el jugador es valida. Es decir: si tiene los dados necesarios en su stock para realizarla una "tirada exitosa".
bool verificar_combinacion(int dado_stock_jugadores[], int conbinacion[]);

// Muestra un mensaje por consala. Dependiendo de si la combinacion ingresada fue válida y si se cumplio el objetivo de una (tirada exitosa o no).
void mensaje_para_la_combinacion(bool es_valida, int contador, string nombre_jugador[], int indice_del_jugador, int objetivo);

#endif // DADOS_H