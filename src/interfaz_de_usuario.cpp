#include "interfaz_de_usuario.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
using namespace std;

void portada() {
    cout << R"(
        _______   ____________  _______   ______  ___    ____  ____  _____
       / ____/ | / / ____/ __ \/ ____/ | / / __ \/   |  / __ \/ __ \/ ___/
      / __/ /  |/ / /__ / /_/ / __/ /  |/ / / / / /| | / / / / / / /\__ \
     / /___/ /|  / __/ / _, _/ /___/ /|  / /_/ / ___ |/ /_/ / /_/ /___/ /
    /_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/\____//____/

                               BIENEVENIDO!
              PRESIONAR LA TECLA ENTER PARA INICIAR EL JUEGO...)"; enter();
}


void menu_principal() {
    cout << R"(
    ╔══════════════════════════════════════════════╗
    ║                MENU PRINCIPAL                ║
    ╠══════════════════════════════════════════════╣
    ║           1 - JUGAR                          ║
    ║           2 - ESTADISTICAS                   ║
    ║           3 - CREDITOS                       ║
    ╠══════════════════════════════════════════════╣
    ║           0 - SALIR                          ║
    ╚══════════════════════════════════════════════╝
    )";
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
    cout << " ";
    cin.get();
}


void continuar() {
    cout << "Enter para continuar..."<<endl;
    cin.get();
}


void esperar_1_segundos() {
    this_thread::sleep_for(chrono::seconds(1));
}


void mensaje_inicio_juego() {
    cout << R"(
       ╔═════════════════════════════════════════════════════════════════════╗
       ║                  ¡HORA DE DECIDIR QUIEN EMPIEZA!                    ║
    ╔══╝═════════════════════════════════════════════════════════════════════╚═╗
    ║        CADA JUGADOR LANZARA UN DADO DE SEIS CARAS Y EL QUE OBTENGA       ║
    ║          EL DADO MAS ALTO SERA EL PRIMERO EN EMPEZAR LA PARTIDA.         ║
    ╠══════════════════════════════════════════════════════════════════════════╝
    ║ ENTER PARA CONTINUAR....║
    ╚═════════════════════════╝)";enter();
}

string centrar(string texto, int ancho) {
    int espacios = ancho - texto.size();
    int izquierda = espacios / 2;
    int derecha = espacios - izquierda;
    return string(izquierda, ' ') + texto + string(derecha, ' ');
}


void mensaje_para_tirar_dado_6_cara( string nombres_jugadores[], int jugador ) {
    int ancho = 35;
    cout << "   ╔═══════════════════════════════════╗"<<endl;
    cout << "   ║" << centrar(nombres_jugadores[jugador], ancho) << "║"<<endl;
    cout << "   ║    ENTER! PARA LANZAR EL DADO     ║"<<endl;
    cout << "   ╚═══════════════════════════════════╝";enter();
    cout <<endl;
}


void mensaje_empate() {
    cout << R"(
       ╔══════════════════════════════════════╗
       ║               ¡EMPATE!               ║
    ╔══╝══════════════════════════════════════╚═╗
    ║       TIENEN QUE REPETIR LA TIRADA.       ║
    ╠═══════════════════════════════════════════╝
    ║ ENTER PARA CONTINUAR...║
    ╚════════════════════════╝)"; enter();
}


void mensaje_para_las_rondas(int ronda, string nombres_jugadores[], int jugador ) {
    int ancho=44;
    cout << "      ╔═══════════════════════════════════════╗"<<endl;
    cout << "      ║                RONDA "<< ronda <<"                ║"<<endl;
    cout << "   ╔══╝═══════════════════════════════════════╚═╗"<<endl;
    cout << "   ║" << centrar( nombres_jugadores[jugador], ancho) << "║"<<endl;
    cout << "   ║    ENTER! PARA LANZAR LOS DADOS OBJETIVO   ║"<<endl;
    cout << "   ╚════════════════════════════════════════════╝";enter();
    cout <<endl;
}


void mensaje_dados_stock(int dodos_stock[], int jugador) {
    cout << "   ╔═══════════════════════════════════════════════════════════╗"<<endl;
    cout << "   ║" << centrar("TENES "+ to_string(dodos_stock[jugador]) + " DODOS DISPONIBLES EN TU STOCK", 59) << "║"<<endl;
    cout << "   ╠═══════════════════════════════════════════════════════════╝"<<endl;
    cout << "   ║ ENTER! PARA LANZAR LOS DODOS...║"<<endl;
    cout << "   ╚════════════════════════════════╝";enter();
}


void mensaje_dados_seleccionados() {

    cout << "╔══════════════════════════════════════════╗"<<endl;
    cout << "║   ESTOS FUERON TUS DADOS SELECCIONADOS   ║"<<endl;
    cout << "╚══════════════════════════════════════════╝"<<endl;
}

void mensaje_gano_la_partida(int puntaje, int suma) {
    int ancho = 63;
    cout << "      ╔═════════════════════════════════════════════════════════╗"<<endl;
    cout << "      ║            FELICIDADES! HAS GANADO LA PARTIDA           ║"<<endl;
    cout << "   ╔══╝═════════════════════════════════════════════════════════╚═╗"<<endl;
    cout << "   ║" << centrar("PUNTAJE OBTENIDO FUE DE: "+to_string(puntaje), ancho) << "║"<<endl;
    cout << "   ║" << centrar("LA SUMA DE LOS DADOS FUE: " + to_string(suma), ancho) << "║"<<endl;
    cout << "   ╠══════════════════════════════════════════════════════════════╝"<<endl;
    cout << "   ║ ENTER PARA CONTINUAR...║"<<endl;
    cout << "   ╚════════════════════════╝";enter();
    cout <<endl;
}


string repete_n_veces_el_caracter(string caracter, int cantidad) {
    string resultado;
    for (int i = 0; i < cantidad; ++i) {
        resultado += caracter;
    }
    return resultado;
}


void intercambiar_si_es_necesario(int &dado1, int &dado2, string &nombre1, string &nombre2) {
    if (dado2 > dado1) {
        swap(dado1, dado2);
        swap(nombre1, nombre2);
    }
}


void mostrar_solo_un_dado(int numero) {
    switch (numero) {
        case 1:
            cout <<"╔═══════╗"<<endl;
            cout <<"║       ║"<<endl;
            cout <<"║   +   ║"<<endl;
            cout <<"║       ║"<<endl;
            cout <<"╚═══════╝"<<endl;
            break;
        case 2:
            cout <<"╔═══════╗"<<endl;
            cout <<"║ +     ║"<<endl;
            cout <<"║       ║"<<endl;
            cout <<"║     + ║"<<endl;
            cout <<"╚═══════╝"<<endl;
            break;
        case 3:
            cout <<"╔═══════╗"<<endl;
            cout <<"║ +     ║"<<endl;
            cout <<"║   +   ║"<<endl;
            cout <<"║     + ║"<<endl;
            cout <<"╚═══════╝"<<endl;
            break;
        case 4:
            cout <<"╔═══════╗"<<endl;
            cout <<"║ +   + ║"<<endl;
            cout <<"║       ║"<<endl;
            cout <<"║ +   + ║"<<endl;
            cout <<"╚═══════╝"<<endl;
            break;
        case 5:
            cout <<"╔═══════╗"<<endl;
            cout <<"║ +   + ║"<<endl;
            cout <<"║   +   ║"<<endl;
            cout <<"║ +   + ║"<<endl;
            cout <<"╚═══════╝"<<endl;
            break;
        case 6:
            cout <<"╔═══════╗"<<endl;
            cout <<"║ +   + ║"<<endl;
            cout <<"║ +   + ║"<<endl;
            cout <<"║ +   + ║"<<endl;
            cout <<"╚═══════╝"<<endl;
            break;
    }
}


void mostrar_dados_12(int dado1, int dado2) {
    int suma = dado1 + dado2;
    cout << "╔═════════╗   ╔═════════╗   ╔═════════╗" << endl;
    cout << "║         ║   ║         ║   ║         ║" << endl;
    cout << "║" << centrar(to_string(dado1), 9) << "║ + ║"
                << centrar(to_string(dado2), 9) << "║ = ║"
                << centrar(to_string(suma),  9) << "║" << endl;
    cout << "║         ║   ║         ║   ║         ║" << endl;
    cout << "╚═════════╝   ╚═════════╝   ╚═════════╝" << endl;
    cout << "  DADO 1        DADO 1       OBJETIVO  " << endl;
}

void limpiar_pantalla(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void mostrar_dados_horizontal(int v[], int dodos_stock, int cant_dados) {
    int indices_validos[11];
    int cantidad_validos = 0;

    if (cant_dados == 0) {
        cout <<"╔═══════╗"<<endl;
        cout <<"║   N   ║"<<endl;
        cout <<"║   A   ║"<<endl;
        cout <<"║   N   ║"<<endl;
        cout <<"╚═══════╝"<<endl;
    }
    else{
        for (int i = 0; i < dodos_stock; ++i) {
            if (v[i] > 0) {
                indices_validos[cantidad_validos++] = i;
            }
        }

        for (int i = 0; i < cantidad_validos; ++i)
            cout << "╔═══════╗  ";
        cout << endl;

        for (int i = 0; i < cantidad_validos; ++i) {
            int d = v[indices_validos[i]];
            if (d == 1) cout << "║       ║  ";
            else if (d == 2 || d == 3) cout << "║ *     ║  ";
            else if (d >= 4 && d <= 6) cout << "║ *   * ║  ";
        }
        cout << endl;

        for (int i = 0; i < cantidad_validos; ++i) {
            int d = v[indices_validos[i]];
            if (d == 1 || d == 3 || d == 5) cout << "║   *   ║  ";
            else if (d == 2 || d == 4) cout << "║       ║  ";
            else if (d == 6) cout << "║ *   * ║  ";
        }
        cout << endl;

        for (int i = 0; i < cantidad_validos; ++i) {
            int d = v[indices_validos[i]];
            if (d == 1) cout << "║       ║  ";
            else if (d == 2 || d == 3) cout << "║     * ║  ";
            else if (d >= 4 && d <= 6) cout << "║ *   * ║  ";
        }
        cout << endl;

        for (int i = 0; i < cantidad_validos; ++i)
            cout << "╚═══════╝  ";
        cout << endl;

        for (int i = 0; i < cantidad_validos; ++i)
            cout << "  [ " << indices_validos[i] + 1 << " ]    ";
        cout << endl;
    }
}


void mensaje_objetivo_cumplido(string nombres[], int jugador, int stock[], int usados, int suma, int puntaje) {
    int oponente = jugador ^ 1;
    const int ancho = 74;
    cout << endl;
    cout << "   ╔══════════════════════════════════════════════════════════════════════════╗"<<endl;
    cout << "   ║" << centrar("FELICIDADES! CUMPLISTE EL OBJETIVO", ancho) << "║"<<endl;
    cout << "   ╠══════════════════════════════════════════════════════════════════════════╣"<<endl;
    cout << "   ║" << centrar("PUNTAJE OBTENIDO FUE DE: "+to_string(puntaje), ancho) << "║"<<endl;
    cout << "   ║" << centrar("LA SUMA DE LOS DADOS FUE: " + to_string(suma), ancho) << "║"<<endl;
    cout << "   ║" << centrar("DADOS UTILIZADOS: " + to_string(usados), ancho) << "║"<<endl;
    cout << "   ║" << centrar("DADOS QUE QUEDARON EN TU STOCK: " + to_string(stock[jugador]), ancho) << "║"<<endl;
    cout << "   ╠══════════════════════════════════════════════════════════════════════════╣"<<endl;
    cout << "   ║" << centrar("LE TRANSFERISTE " + to_string(usados) + " DADOS A " + nombres[oponente], ancho) << "║"<<endl;
    cout << "   ╠══════════════════════════════════════════════════════════════════════════╝"<<endl;
    cout << "   ║ ENTER PARA CONTINUAR....║"<<endl;
    cout << "   ╚═════════════════════════╝";enter();
    cout <<endl;
}



void mensaje_objetivo_no_cumplido( int cant_dados_stock[], int jugador,  int ronda, string nombre_jugador[], int suma) {
    const int ancho = 74;
    int oponente = jugador ^ 1;

    if (ronda < 3) {
        cout << endl;
        cout << "   ╔══════════════════════════════════════════════════════════════════════════╗"<<endl;
        cout << "   ║" << centrar("LO SIENTO, NO CUMPLISTE EL OBJETIVO", ancho) << "║"<<endl;
        cout << "   ╠══════════════════════════════════════════════════════════════════════════╣"<<endl;
        cout << "   ║" << centrar("PUNTAJE OBTENIDO FUE DE: O", ancho) << "║"<<endl;
        cout << "   ║" << centrar("LA SUMA DE LOS DADOS FUE: " + to_string(suma), ancho) << "║"<<endl;
        cout << "   ║" << centrar(" SE TE PENALIZADA AGREGANDON UN DADO MAS A TU STOCK ", ancho) << "║"<<endl;
        cout << "   ║" << centrar(" AHORA TENDRA EN TU STOCK " + to_string(cant_dados_stock[jugador]) + " DADOS", ancho) << "║"<<endl;
        cout << "   ╠══════════════════════════════════════════════════════════════════════════╝"<<endl;
        cout << "   ║ ENTER PARA CONTINUAR...║"<<endl;
        cout << "   ╚════════════════════════╝";enter();
        cout <<endl;
    }
    else {
        cout << endl;
        cout << "   ╔══════════════════════════════════════════════════════════════════════════╗"<<endl;
        cout << "   ║" << centrar("LO SIENTO, NO CUMPLISTE EL OBJETIVO", ancho) << "║"<<endl;
        cout << "   ╠══════════════════════════════════════════════════════════════════════════╣"<<endl;
        cout << "   ║" << centrar("PUNTAJE OBTENIDO FUE DE: O", ancho) << "║"<<endl;
        cout << "   ║" << centrar("LA SUMA DE LOS DADOS FUE: " + to_string(suma), ancho) << "║"<<endl;
        cout << "   ║" << centrar("SE LE QUITARA UN DADO DEL STOCK A " + nombre_jugador[oponente], ancho) << "║"<<endl;
        cout << "   ║" << centrar("POR SER LA ULTIMA RONDA DE LA PARTIDA Y", ancho) << "║"<<endl;
        cout << "   ║" << centrar("NO HABER CUMPLIDO EL OBJETIVO", ancho) << "║"<<endl;
        cout << "   ╠══════════════════════════════════════════════════════════════════════════╝"<<endl;
        cout << "   ║ ENTER PARA CONTINUAR...║"<<endl;
        cout << "   ╚════════════════════════╝";enter();
        cout <<endl;
    }
}


void mensaje_objetivo_no_cumplido_mas_stock_max( int cant_dados_stock[], int jugador,  int ronda, string nombre_jugador[], int suma) {
        cout << endl;
        cout << "   ╔══════════════════════════════════════════════════════════════════════════╗"<<endl;
        cout << "   ║" << centrar("LO SIENTO, NO CUMPLISTE EL OBJETIVO", 74) << "║"<<endl;
        cout << "   ╠══════════════════════════════════════════════════════════════════════════╣"<<endl;
        cout << "   ║" << centrar("PUNTAJE OBTENIDO FUE DE: O", 74) << "║"<<endl;
        cout << "   ║" << centrar("LA SUMA DE LOS DADOS FUE: " + to_string(suma), 74) << "║"<<endl;
        cout << "   ║" << centrar("TE QUEDARA CON LA MISMA CANTIDAD DE DADOS EN EL STOCK", 74) << "║"<<endl;
        cout << "   ║" << centrar("POR QUE NO SE TE PUEDE PENALIZAR " + nombre_jugador[jugador], 74) << "║"<<endl;
        cout << "   ╠══════════════════════════════════════════════════════════════════════════╝"<<endl;
        cout << "   ║ ENTER PARA CONTINUAR...║"<<endl;
        cout << "   ╚════════════════════════╝";enter();
        cout <<endl;
}

