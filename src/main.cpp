#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "interfaz_de_usuario.h"
#include "dados.h"
#include "puntaje.h"
#include "estadistica.h"
using namespace std;

int main() {
    srand(time(nullptr));

    //Definiciones de las variables
    const int CANTIDAD_JUGADORES = 2;

    const int CANT_CARAS_DADO_STOCK = 6;
    const int CANT_DADOS_STOCK_INICIAL = 6;

    const int CANT_CARAS_DADO_OBJETIVO = 12;
    const int CANT_DADOS_OBJETIVO = 2;

    const int CANT_RONDA = 3;

    // Mostrando el nombre del juego
    portada();

    // Mostrando el menu
    menu_principal();

    // Se ejecuta el juego solo si la opcion de es igual a 1. Que seria jugar!
    if (opcion_seleccionada()==1) {
        cin.ignore();

        //Creacion de variables para el juego.
        string nombres_jugadores[CANTIDAD_JUGADORES];

        int dados_objetivo[CANT_DADOS_OBJETIVO]{};

        int dado_stock_jugadores[CANTIDAD_JUGADORES] {0};

        int puntaje_acumulado_por_jugadores[CANTIDAD_JUGADORES] {0};

        int puntajes_por_rondas_jugadores[CANTIDAD_JUGADORES*CANT_RONDA] {0};

        int cant_dados_stock[CANTIDAD_JUGADORES] = {CANT_DADOS_STOCK_INICIAL, CANT_DADOS_STOCK_INICIAL};

        int objetivo=0;

        bool seguir_jugando = true;

        int puntaje=0;

        // Ingreso de los nombres de los jugadores.
        for (int jugador = 0; jugador < CANTIDAD_JUGADORES; jugador++) {
            cout << "Nombre del jugador " << jugador + 1 << ": ";
            getline(cin, nombres_jugadores[jugador]);
        }

        mensaje_inicio_juego();

        do {
            for (int jugador = 0; jugador < CANTIDAD_JUGADORES; jugador++) {
                // El que ingreso primero su nombre sera el primero en lanzar el dado para saber quién empieza la partida.
                cout << endl;
                mensaje_para_tirar_dado_6_cara(nombres_jugadores, jugador);
                esperar_1_segundos();
                dado_stock_jugadores[jugador] = tirar_dado(CANT_CARAS_DADO_STOCK);
                mostrar_solo_un_dado(dado_stock_jugadores[jugador]);
            }
            // Esta funcion intercambia los nombres de los jugadores para que el Jugador 1 sea siempre quien comience la partida.
            intercambiar_si_es_necesario(dado_stock_jugadores[0], dado_stock_jugadores[1], nombres_jugadores[0], nombres_jugadores[1]);

            // Se muestra un mensaje de empate si ambos jugadores sacaron el mismo dado.
            if (dado_stock_jugadores[0]==dado_stock_jugadores[1]) {
                mensaje_empate();
            }
        }while (dado_stock_jugadores[0] == dado_stock_jugadores[1]);

        // Bucle para las rondas.
        for (int ronda=1; ronda<=CANT_RONDA; ronda++) {

            //Bucle para los jugadores.
            for (int jugador = 0; jugador < CANTIDAD_JUGADORES; jugador++) {
                esperar_1_segundos();

                // Se muestra el mensaje de las rondas con el nombre del jugador.
                mensaje_para_las_rondas(ronda, nombres_jugadores, jugador);

                // Se lanzan los 2 dados objetivo.
                tirar_dados(dados_objetivo, CANT_DADOS_OBJETIVO, CANT_CARAS_DADO_OBJETIVO);
                objetivo = dados_objetivo[0] + dados_objetivo[1];
                esperar_1_segundos();

                //Se muestran los dados objetivo por pantalla.
                mostrar_dados_12(dados_objetivo[0], dados_objetivo[1]);

                int dados [cant_dados_stock[jugador]] {0};
                int dados_seleccionados [cant_dados_stock[jugador]] {0};

                // Se generan los dados del jugador segun su stock de dados.
                tirar_dados(dados, cant_dados_stock[jugador], CANT_CARAS_DADO_STOCK);
                esperar_1_segundos();
                mensaje_dados_stock();
                mostrar_dados_horizontal(dados,cant_dados_stock[jugador]);

                // Se seleccionan los dados del jugador.
                seleccionar_dados(dados, dados_seleccionados,cant_dados_stock[jugador]);
                mensaje_dados_seleccionados();
                mostrar_dados_horizontal(dados_seleccionados,cant_dados_stock[jugador]);
                cin.get();

                int suma_dados_seleccionados = sumar_dados(dados_seleccionados, cant_dados_stock[jugador]);
                int cantidad_dados_seleccionados = contador_dados(dados_seleccionados, cant_dados_stock[jugador]);

                if (cantidad_dados_seleccionados == cant_dados_stock[jugador] && suma_dados_seleccionados == objetivo) {
                    // Mensaje para el ganador.
                    mensaje_gano_la_partida(nombres_jugadores, jugador);
                    // Se calcula el puntaje del jugador.
                    puntaje = calcular_puntaje(suma_dados_seleccionados, cantidad_dados_seleccionados)+10000;
                    // Se guarda el puntaje total del jugador en un vector.
                    puntaje_acumulado_por_jugadores[jugador]+= puntaje;
                    // Se guarda el puntaje del jugador para la estadistica.
                    guardar_puntaje_por_ronda(jugador, ronda, puntaje, puntajes_por_rondas_jugadores, nombres_jugadores);
                    // Un corte para la partida ya que hay un ganador.
                    seguir_jugando = false;
                    break;

                } else if (suma_dados_seleccionados == objetivo) {
                    // Se calcula el puntaje del jugador.
                    puntaje = calcular_puntaje(suma_dados_seleccionados, cantidad_dados_seleccionados);
                    // Funcion para tranferir los dados al oponent del jugador
                    transferir_dados(jugador, cant_dados_stock, cantidad_dados_seleccionados);
                    // Se muestra un mensaje de que el jugador cumple con el objetivo.
                    mensaje_objetivo_cumplido(nombres_jugadores, jugador, cant_dados_stock, cantidad_dados_seleccionados, suma_dados_seleccionados);
                    // Se guarda el puntaje total del jugador en un vector.
                    puntaje_acumulado_por_jugadores[jugador]+= puntaje;
                    // Se guarda el puntaje del jugador para la estadistica.
                    guardar_puntaje_por_ronda(jugador, ronda, puntaje, puntajes_por_rondas_jugadores, nombres_jugadores);
                }
                else {
                    // Se calcula el indice del rival del jugador.
                    int opener =  jugador ^ 1;
                    // Transferencia de los dados del jugador al rival. Solo si el rival tiene 1 o mas dados.
                    if (cant_dados_stock[opener]>1) {
                        cant_dados_stock[opener]--;
                        cant_dados_stock[jugador]++;
                    }
                    // Se muestra un mensaje de que el jugador no cumple con el objetivo. Segun la ronda o la cantidad de dados que tiene en el stock el oponente.
                    mensaje_objetivo_no_cumplido( cant_dados_stock, jugador, ronda, nombres_jugadores);
                    // Se guarda el puntaje del jugador para la estadistica.
                    guardar_puntaje_por_ronda(jugador, ronda, 0, puntajes_por_rondas_jugadores, nombres_jugadores);
                }
            }
            if (!seguir_jugando){
                break;
            }
        }
         mostrar_estadistica(puntajes_por_rondas_jugadores, nombres_jugadores, CANT_RONDA, puntaje_acumulado_por_jugadores);
    }

    return 0;
}