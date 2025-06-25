#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "interfaz_de_usuario.h"
#include "dados.h"
#include "puntaje.h"
#include "estadistica.h"
using namespace std;

void jugar(int cantidad_jugadores, int cant_ronda, int cant_dados_objetivo, int cant_dados_stock_inicial, int cant_caras_dado_stock, int cant_caras_dado_objetivo, string ranking_jugadores[], int ranking_puntajes[], int longitud_ranking) {
    cin.ignore();

        string nombres_jugadores[cantidad_jugadores];

        int dados_objetivo[cant_dados_objetivo]{};

        int dado_stock_jugadores[cantidad_jugadores] {0};

        int puntaje_acumulado_por_jugadores[cantidad_jugadores] {0};

        int puntajes_por_rondas_jugadores[cantidad_jugadores*cant_ronda] {0};

        int cant_dados_stock[cantidad_jugadores] = {cant_dados_stock_inicial, cant_dados_stock_inicial};

        int objetivo=0;

        bool seguir_jugando = true;

        int puntaje=0;

        for (int jugador = 0; jugador < cantidad_jugadores; jugador++) {
            cout << "Nombre del jugador " << jugador + 1 << ": ";
            getline(cin, nombres_jugadores[jugador]);
        }

        mensaje_inicio_juego();

        do {
            for (int jugador = 0; jugador < cantidad_jugadores; jugador++) {
                cout << endl;
                mensaje_para_tirar_dado_6_cara(nombres_jugadores, jugador);
                esperar_1_segundos();
                dado_stock_jugadores[jugador] = tirar_dado(cant_caras_dado_stock);
                mostrar_solo_un_dado(dado_stock_jugadores[jugador]);
            }

            intercambiar_si_es_necesario(dado_stock_jugadores[0], dado_stock_jugadores[1], nombres_jugadores[0], nombres_jugadores[1]);

            if (dado_stock_jugadores[0]==dado_stock_jugadores[1]) {
                mensaje_empate();
            }
        }while (dado_stock_jugadores[0] == dado_stock_jugadores[1]);

        for (int ronda=1; ronda<=cant_ronda; ronda++) {

            for (int jugador = 0; jugador < cantidad_jugadores; jugador++) {
                esperar_1_segundos();

                mensaje_para_las_rondas(ronda, nombres_jugadores, jugador);

                tirar_dados(dados_objetivo, cant_dados_objetivo, cant_caras_dado_objetivo);
                objetivo = dados_objetivo[0] + dados_objetivo[1];
                esperar_1_segundos();

                mostrar_dados_12(dados_objetivo[0], dados_objetivo[1]);

                int dados_stock [cant_dados_stock[jugador]] {0};
                int dados_seleccionados [cant_dados_stock[jugador]] {0};

                tirar_dados(dados_stock, cant_dados_stock[jugador], cant_caras_dado_stock);
                esperar_1_segundos();

                mensaje_dados_stock(cant_dados_stock, jugador);
                mostrar_dados_horizontal(dados_stock,cant_dados_stock[jugador], true);

                seleccionar_dados(dados_stock, dados_seleccionados,cant_dados_stock[jugador]);

                int cantidad_dados_seleccionados = contador_dados(dados_seleccionados, cant_dados_stock[jugador]);
                int suma_dados_seleccionados = sumar_dados(dados_seleccionados, cant_dados_stock[jugador]);

                mensaje_dados_seleccionados();
                mostrar_dados_horizontal(dados_seleccionados, cantidad_dados_seleccionados, false);
                cin.get();

                if (cantidad_dados_seleccionados == cant_dados_stock[jugador] && suma_dados_seleccionados == objetivo) {

                    puntaje = calcular_puntaje(suma_dados_seleccionados, cantidad_dados_seleccionados)+10000;

                    puntaje_acumulado_por_jugadores[jugador]+= puntaje;

                    mensaje_gano_la_partida(puntaje,dado_stock_jugadores[jugador]);

                    guardar_puntaje_por_ronda(jugador, ronda, puntaje, puntajes_por_rondas_jugadores);

                    seguir_jugando = false;
                    break;
                } else if (suma_dados_seleccionados == objetivo) {

                    puntaje = calcular_puntaje(suma_dados_seleccionados, cantidad_dados_seleccionados);

                    transferir_dados(jugador, cant_dados_stock, cantidad_dados_seleccionados);

                    mensaje_objetivo_cumplido(nombres_jugadores, jugador, cant_dados_stock, cantidad_dados_seleccionados, suma_dados_seleccionados, puntaje);

                    puntaje_acumulado_por_jugadores[jugador]+= puntaje;

                    guardar_puntaje_por_ronda(jugador, ronda, puntaje, puntajes_por_rondas_jugadores);
                }
                else {

                    penalizar_jugador(jugador, cant_dados_stock, ronda, nombres_jugadores, suma_dados_seleccionados);

                    guardar_puntaje_por_ronda(jugador, ronda, 0, puntajes_por_rondas_jugadores);
                }
            }
            if (!seguir_jugando){
                break;
            }
        }

        int resultado_final = obtener_resultado_final(puntaje_acumulado_por_jugadores);
        anunciar_ganador_o_empate(resultado_final, nombres_jugadores);
        mostrar_resumen(puntajes_por_rondas_jugadores, nombres_jugadores, cant_ronda, puntaje_acumulado_por_jugadores);
        guardar_resultado(nombres_jugadores, puntaje_acumulado_por_jugadores, resultado_final,ranking_jugadores, ranking_puntajes, longitud_ranking);
}

void estadisticas(string jugadores[], int puntajes[]) {
    cout << "\n>>> Estadísticas del juego no implementadas aún.\n";
    cout << "Preciona enter para volver al menu principal.\n";
    enter();
}



int main() {
    srand(time(nullptr));

    const int CANTIDAD_JUGADORES = 2;

    const int CANT_CARAS_DADO_STOCK = 6;
    const int CANT_DADOS_STOCK_INICIAL = 6;

    const int CANT_CARAS_DADO_OBJETIVO = 12;
    const int CANT_DADOS_OBJETIVO = 2;

    const int CANT_RONDA = 3;

    const int LONGITUD_RANKING = 10;

    string ranking_jugadores [LONGITUD_RANKING] = {};
    int ranking_puntajes [LONGITUD_RANKING] = {};

    portada();

    int opcion; 

    do
    {
        menu_principal();

        cout << " Ingresar opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:                
                jugar(CANTIDAD_JUGADORES, CANT_RONDA, CANT_DADOS_OBJETIVO, CANT_DADOS_STOCK_INICIAL, CANT_CARAS_DADO_STOCK, CANT_CARAS_DADO_OBJETIVO, ranking_jugadores, ranking_puntajes, LONGITUD_RANKING);
                break;
            case 2:
                mostrar_ranking(ranking_jugadores, ranking_puntajes, LONGITUD_RANKING);
                enter();
                break;
            case 3:
                credito();
                enter();
                break;
            case 0:
                cout << "\n>>> Saliendo del juego...\n";
                break;
            default:
                cout << "\n>>> Opción no válida.\n";
                break;
        }
    } while (opcion != 0);  

    return 0;
}