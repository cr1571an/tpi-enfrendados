// Definiciones de las funciones de calculadora.h
#include "interfaz_de_usuario.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void portada() {
    cout << R"(
        _______   ____________  _______   ______  ___    ____  ____  _____
       / ____/ | / / ____/ __ \/ ____/ | / / __ \/   |  / __ \/ __ \/ ___/
      / __/ /  |/ / /__ / /_/ / __/ /  |/ / / / / /| | / / / / / / /\__ \
     / /___/ /|  / __/ / _, _/ /___/ /|  / /_/ / ___ |/ /_/ / /_/ /___/ /
    /_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/\____//____/

)";
}
void menu() {
    cout << "\n";
    cout << " +-----------------------+" << endl;
    cout << " |     MENU PRINCIPAL    |" << endl;
    cout << " +-----------------------+" << endl;
    cout << " |  1 - JUGAR            |" << endl;
    cout << " |  2 - ESTADISTICAS     |" << endl;
    cout << " |  3 - CREDITOS         |" << endl;
    cout << " +-----------------------+" << endl;
    cout << " |  0 - SALIR            |" << endl;
    cout << " +-----------------------+" << endl;
    cout << "\n";
}
int opcion_seleccionada () {
    int  opcion;
    do {
        cout << " Ingresar opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 0:
                return 0;
                break;
            case 1:
                return 1;
                break;
            case 2:
                return 2;
                break;
            case 3:
                return 3;
                break;
            default:
                cout << "Debes elegir una opcion del menu." << endl;
        }
    }while(opcion != 0);
    return opcion;
}

void enter() {
    cout << "Enter para el lanzamiento del dado..."<<endl;
    cin.get();
}

void esperar_1_segundos() {
    this_thread::sleep_for(chrono::seconds(1));
}

void anuncio_Jugador(int jugador1, int jugador2, string nombre1, string nombre2) {
    if (jugador1 > jugador2) {
        cout << nombre1 << " comienza." << endl;
    } else if (jugador2 > jugador1) {
        cout << nombre2 << " comienza." << endl;
    } else {
        cout << "Empate!. Ambos sacaron lo mismo. Vulvan a lazar los dados."<< endl;
    }
}

void intercambiar_si_es_necesario(int &dado1, int &dado2, string &nombre1, string &nombre2) {
    if (dado2 > dado1) {
        swap(dado1, dado2);
        swap(nombre1, nombre2);
    }
}



void mostrar_dado(int numero) {
    cout << "+-------+" << endl;
    switch (numero) {
        case 1:
            cout << "|       |" << endl;
            cout << "|   *   |" << endl;
            cout << "|       |" << endl;
            break;
        case 2:
            cout << "| *     |" << endl;
            cout << "|       |" << endl;
            cout << "|     * |" << endl;
            break;
        case 3:
            cout << "| *     |" << endl;
            cout << "|   *   |" << endl;
            cout << "|     * |" << endl;
            break;
        case 4:
            cout << "| *   * |" << endl;
            cout << "|       |" << endl;
            cout << "| *   * |" << endl;
            break;
        case 5:
            cout << "| *   * |" << endl;
            cout << "|   *   |" << endl;
            cout << "| *   * |" << endl;
            break;
        case 6:
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            break;
    }
    cout << "+-------+" << endl;
}

void mostrar_dados_12(int dado1, int dado2) {

    cout << "+---------+   +---------+" << endl;
    cout << "|         |   |         |" << endl;
    cout << "|    " << dado1 << "    |   |    " << dado2 << "    |" << endl;
    cout << "|         |   |         |" << endl;
    cout << "+---------+   +---------+" << endl;

    cout << "El objetivo es alcanzar un total de "<<dado1+dado2<<"."<<endl;
}