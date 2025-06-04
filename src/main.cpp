#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "funciones.h"
using namespace std;




int main() {
    srand(time(nullptr));
    /// Nombre de los jugadores.
    string nombre_1, nombre_2;

    /// Dados de 6 cara para ver quien empieza.
    int dado_jugador1, dado_jugador2;

    // Mostrando el nombre del juego
    portada();

    // Mostrando el menu
    menu();

    // Se ejecuta solo si la opcion de es igual a 1. Que seria jugar
    if (opcion_seleccionada()==1) {
        cin.ignore();

        // Ingreso de los nombres de los jugadores.
        cout << "Nombre del jugador 1: ";
        getline(cin, nombre_1);
        cout << "Nombre del jugador 2: ";
        getline(cin, nombre_2);

        cout << "Tendran que lanzar un dado cada uno para ver quien empieza la ronda. El que obtenga el dado mas alto comienza."<<endl;

        do {
            // El que ingreso primero su nombre sera el primero en lanzar el dado para saber quién empieza la partida.
            cout << "Primero lanza " << nombre_1 << ":"<<endl;
            enter();
            esperar_1_segundos();
            dado_jugador1 = dado_de_6_cada();
            mostrar_dado(dado_jugador1);

            // Turno del segundo jugador en lanzar el dado.
            cout << "Ahora tu turno " << nombre_2 << "."<<endl;
            enter();
            esperar_1_segundos();
            dado_jugador2 = dado_de_6_cada();
            mostrar_dado(dado_jugador2);

            // Esta funcion anuncia al jugador que empieza la partida.
            anuncio_Jugador(dado_jugador1, dado_jugador2, nombre_1, nombre_2);
        }while (dado_jugador1 == dado_jugador2);

        // Esta funcion intercambia los nombres de los jugadores para que el Jugador 1 sea siempre quien comience la partida.
        intercambiar_si_es_necesario(dado_jugador1, dado_jugador2, nombre_1, nombre_2);

        // Aca se generan 6 valores al azar y se guardan en un vector de 12 elementos.
        // Le puse 12 elementos al vector para que tambien pueda almacenar los dados que le dara el oponente.
        int v_dado_de_6_cara_jugador1[12]{};
        simular_tiradas_dado_6(v_dado_de_6_cara_jugador1);

        // A esta parte le falta completar
        for (int i=1; i<=3; i++) {
            esperar_1_segundos();
            cout << "Ronda " << i << endl;
            int dado_1_objetivo_jugador1 = tirar_dados_objetivo();
            int dado_2_objetivo_jugador1 = tirar_dados_objetivo();
            int objetivo = dado_1_objetivo_jugador1 + dado_2_objetivo_jugador1;
            esperar_1_segundos();
            mostrar_dados_12(dado_1_objetivo_jugador1, dado_2_objetivo_jugador1);
            cout << "Dados stock.[ " ;
            for(int f=0; f<12; f++){
                if(v_dado_de_6_cara_jugador1[f]>0){
                    cout << v_dado_de_6_cara_jugador1[f] << " ";
                }
            }
            cout <<"]"<< endl;

        }
    }

    return 0;
}