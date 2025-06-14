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

    const int CANTIDAD_JUGADORES = 2;

    const int CANT_CARAS_DADO_STOCK = 6;
    const int CANT_DADOS_STOCK_INICIAL = 6;

    const int CANT_CARAS_DADO_OBJETIVO = 12;
    const int CANT_DADOS_OBJETIVO = 2;

    const int CANT_RONDA = 3;

    portada();

    menu_principal();

    int opcion = opcion_seleccionada();

    if (opcion==1) {
        cin.ignore();

        string nombres_jugadores[CANTIDAD_JUGADORES];

        int dados_objetivo[CANT_DADOS_OBJETIVO]{};

        int dado_stock_jugadores[CANTIDAD_JUGADORES] {0};

        int puntaje_acumulado_por_jugadores[CANTIDAD_JUGADORES] {0};

        int puntajes_por_rondas_jugadores[CANTIDAD_JUGADORES*CANT_RONDA] {0};

        int cant_dados_stock[CANTIDAD_JUGADORES] = {CANT_DADOS_STOCK_INICIAL, CANT_DADOS_STOCK_INICIAL};

        int objetivo=0;

        bool seguir_jugando = true;

        int puntaje=0;

        for (int jugador = 0; jugador < CANTIDAD_JUGADORES; jugador++) {
            cout << "Nombre del jugador " << jugador + 1 << ": ";
            getline(cin, nombres_jugadores[jugador]);
        }

        mensaje_inicio_juego();

        do {
            for (int jugador = 0; jugador < CANTIDAD_JUGADORES; jugador++) {
                cout << endl;
                mensaje_para_tirar_dado_6_cara(nombres_jugadores, jugador);
                esperar_1_segundos();
                dado_stock_jugadores[jugador] = tirar_dado(CANT_CARAS_DADO_STOCK);
                mostrar_solo_un_dado(dado_stock_jugadores[jugador]);
            }

            intercambiar_si_es_necesario(dado_stock_jugadores[0], dado_stock_jugadores[1], nombres_jugadores[0], nombres_jugadores[1]);

            if (dado_stock_jugadores[0]==dado_stock_jugadores[1]) {
                mensaje_empate();
            }
        }while (dado_stock_jugadores[0] == dado_stock_jugadores[1]);

        for (int ronda=1; ronda<=CANT_RONDA; ronda++) {

            for (int jugador = 0; jugador < CANTIDAD_JUGADORES; jugador++) {
                esperar_1_segundos();

                mensaje_para_las_rondas(ronda, nombres_jugadores, jugador);

                tirar_dados(dados_objetivo, CANT_DADOS_OBJETIVO, CANT_CARAS_DADO_OBJETIVO);
                objetivo = dados_objetivo[0] + dados_objetivo[1];
                esperar_1_segundos();

                mostrar_dados_12(dados_objetivo[0], dados_objetivo[1]);

                int dados [cant_dados_stock[jugador]] {0};
                int dados_seleccionados [cant_dados_stock[jugador]] {0};

                tirar_dados(dados, cant_dados_stock[jugador], CANT_CARAS_DADO_STOCK);
                esperar_1_segundos();
                mensaje_dados_stock();
                mostrar_dados_horizontal(dados,cant_dados_stock[jugador]);

                seleccionar_dados(dados, dados_seleccionados,cant_dados_stock[jugador]);
                mensaje_dados_seleccionados();
                mostrar_dados_horizontal(dados_seleccionados,cant_dados_stock[jugador]);
                cin.get();

                int suma_dados_seleccionados = sumar_dados(dados_seleccionados, cant_dados_stock[jugador]);
                int cantidad_dados_seleccionados = contador_dados(dados_seleccionados, cant_dados_stock[jugador]);

                if (cantidad_dados_seleccionados == cant_dados_stock[jugador] && suma_dados_seleccionados == objetivo) {

                    mensaje_gano_la_partida(nombres_jugadores, jugador);

                    puntaje = calcular_puntaje(suma_dados_seleccionados, cantidad_dados_seleccionados)+10000;

                    puntaje_acumulado_por_jugadores[jugador]+= puntaje;

                    guardar_puntaje_por_ronda(jugador, ronda, puntaje, puntajes_por_rondas_jugadores, nombres_jugadores);

                    seguir_jugando = false;
                    break;
                } else if (suma_dados_seleccionados == objetivo) {

                    puntaje = calcular_puntaje(suma_dados_seleccionados, cantidad_dados_seleccionados);

                    transferir_dados(jugador, cant_dados_stock, cantidad_dados_seleccionados);

                    mensaje_objetivo_cumplido(nombres_jugadores, jugador, cant_dados_stock, cantidad_dados_seleccionados, suma_dados_seleccionados);

                    puntaje_acumulado_por_jugadores[jugador]+= puntaje;

                    guardar_puntaje_por_ronda(jugador, ronda, puntaje, puntajes_por_rondas_jugadores, nombres_jugadores);
                }
                else {
                    int oponente =  jugador ^ 1;
                    if (cant_dados_stock[oponente]>1) {
                        cant_dados_stock[oponente]--;
                        cant_dados_stock[jugador]++;
                        mensaje_objetivo_no_cumplido( cant_dados_stock, jugador, ronda, nombres_jugadores);
                    }
                    else {
                    mensaje_objetivo_no_cumplido_mas_stock_max(cant_dados_stock, jugador, ronda, nombres_jugadores);
                    }

                    guardar_puntaje_por_ronda(jugador, ronda, 0, puntajes_por_rondas_jugadores, nombres_jugadores);
                }
            }
            if (!seguir_jugando){
                break;
            }
        }
         mostrar_estadistica(puntajes_por_rondas_jugadores, nombres_jugadores, CANT_RONDA, puntaje_acumulado_por_jugadores);
    }
    if (opcion==0) {
        exit(0);
    }
    return 0;
}