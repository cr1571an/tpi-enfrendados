#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "interfaz_de_usuario.h"
#include "dados.h"
#include "puntaje.h"

using namespace std;




int main() {
    srand(time(nullptr));

    
    const int CANT_CARAS_DADO_STOCK = 6;    
    const int CANT_DADOS_STOCK_INICIAL = 6;

    const int CANT_CARAS_DADO_OBJETIVO = 12;
    const int CANT_DADOS_OBJETIVO = 2;

    const int TRANSFERIR_DADOS = 6;

    const int CANTIDAD_JUGADORES = 2;

    const int MAXIMA_CANTIDAD_DADOS_JUGADOR = CANT_DADOS_STOCK_INICIAL + TRANSFERIR_DADOS;

    
    int cant_dados_stock[CANTIDAD_JUGADORES] = {CANT_DADOS_STOCK_INICIAL, CANT_DADOS_STOCK_INICIAL};    

    string nombres_jugadores[CANTIDAD_JUGADORES];

    int dado_stock_jugadores[CANTIDAD_JUGADORES] = {0};
    int puntajes_jugadores[CANTIDAD_JUGADORES] = {0};

    bool seguir_jugando = true;
    
    limpiar_pantalla();
    // Mostrando el nombre del juego
    portada();

    // Mostrando el menu
    menu();

    // Se ejecuta solo si la opcion de es igual a 1. Que seria jugar
    if (opcion_seleccionada()==1) {
        cin.ignore();

        for (int jugador = 0; jugador < CANTIDAD_JUGADORES; jugador++) {
            cout << "Nombre del jugador " << jugador + 1 << ": ";
            getline(cin, nombres_jugadores[jugador]);
        }

        cout << "Tendran que lanzar un dado cada uno para ver quien empieza la ronda. El que obtenga el dado mas alto comienza."<<endl;

        do {

            for (int jugador = 0; jugador < CANTIDAD_JUGADORES; jugador++) {
                // El que ingreso primero su nombre sera el primero en lanzar el dado para saber quién empieza la partida.
                cout << "Es el turno de " << nombres_jugadores[jugador] << ":"<<endl;
                enter();
                esperar_1_segundos();
                dado_stock_jugadores[jugador] = tirar_dado(CANT_CARAS_DADO_STOCK);
                mostrar_dado(dado_stock_jugadores[jugador]);                
            }

            // Esta funcion anuncia al jugador que empieza la partida.
            anuncio_Jugador(dado_stock_jugadores[0], dado_stock_jugadores[1], nombres_jugadores[0], nombres_jugadores[1]);
        }while (dado_stock_jugadores[0] == dado_stock_jugadores[1]);

        // Esta funcion intercambia los nombres de los jugadores para que el Jugador 1 sea siempre quien comience la partida.
        intercambiar_si_es_necesario(dado_stock_jugadores[0], dado_stock_jugadores[1], nombres_jugadores[0], nombres_jugadores[1]);
        
        continuar();
        limpiar_pantalla();

        for (int ronda=1; ronda<=3; ronda++) {
            for (int jugador = 0; jugador < CANTIDAD_JUGADORES; jugador++) {             
                esperar_1_segundos();
                cout << "Ronda " << ronda << endl;
                cout << "Turno de " << nombres_jugadores[jugador] << "." << endl;
                
                int dado_1_objetivo_jugador1 = tirar_dado(CANT_CARAS_DADO_OBJETIVO);
                int dado_2_objetivo_jugador1 = tirar_dado(CANT_CARAS_DADO_OBJETIVO);
                int objetivo = dado_1_objetivo_jugador1 + dado_2_objetivo_jugador1;

                esperar_1_segundos();
                mostrar_dados_12(dado_1_objetivo_jugador1, dado_2_objetivo_jugador1);        
                cout << "El objetivo de " << nombres_jugadores[jugador] << " es: " << objetivo << endl;

                int dados [cant_dados_stock[jugador]]= {0};
                int dados_seleccionados [cant_dados_stock[jugador]] = {0};

                tirar_dados(dados, cant_dados_stock[jugador], CANT_CARAS_DADO_STOCK);
                mostrar_dados(dados, cant_dados_stock[jugador]);
                continuar();
                seleccionar_dados(dados, dados_seleccionados,cant_dados_stock[jugador]);
                continuar();
                limpiar_pantalla();
                mostrar_dados(dados_seleccionados, cant_dados_stock[jugador]);
                continuar();
                int suma_dados_seleccionados = sumar_dados(dados_seleccionados, cant_dados_stock[jugador]);
                int cantidad_dados_seleccionados = contador_dados(dados_seleccionados, cant_dados_stock[jugador]);

                cout << "La suma de los dados seleccionados es: " << suma_dados_seleccionados << " y la cantidad de dados seleccionados es: " << cantidad_dados_seleccionados <<endl;
                
                if (suma_dados_seleccionados == objetivo && cantidad_dados_seleccionados == cant_dados_stock[jugador]) {
                    cout << nombres_jugadores[jugador] << " Felicidades! Cumpliste el objetivo de la ronda y ademas ganaste el juego. =)"<<endl;
                    puntajes_jugadores[jugador] += calcular_puntaje(suma_dados_seleccionados, cantidad_dados_seleccionados);
                    puntajes_jugadores[jugador] += 10000;
                    cout << "Tienes ahora " << puntajes_jugadores[jugador] << " puntos."<<endl;
                    seguir_jugando = false;

                    continuar();
                    limpiar_pantalla();
                    break;
                } else if (suma_dados_seleccionados == objetivo) {
                    cout << nombres_jugadores[jugador] << " Felicidades! Cumpliste el objetivo de la ronda."<<endl;
                    puntajes_jugadores[jugador] += calcular_puntaje(suma_dados_seleccionados, cantidad_dados_seleccionados);
                    transferir_dados(jugador, cant_dados_stock, cantidad_dados_seleccionados);
                    cout << "Tienes ahora " << cant_dados_stock[jugador] << " dados de stock."<<endl;
                    cout << "Tienes ahora " << puntajes_jugadores[jugador] << " puntos."<<endl;

                    continuar();
                    limpiar_pantalla();
                }
                else {
                    cout << nombres_jugadores[jugador] << " Lo siento, no cumpliste el objetivo de la ronda."<<endl;
                    cout << "Se te penaliza agregandote un dado de stock."<<endl;
                    penalizar_jugador(jugador, cant_dados_stock);                    
                    cout << "Tienes ahora " << cant_dados_stock[jugador] << " dados de stock."<<endl;
                    
                    continuar();
                    limpiar_pantalla();
                }
            }
            if (!seguir_jugando){
                break;
            }
        }
    }

    return 0;
}