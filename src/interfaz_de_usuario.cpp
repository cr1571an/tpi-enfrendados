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

void enter() {
    cout << " ";
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


void mensaje_dados_stock(int dados_stock[], int jugador) {
    cout << "   ╔═══════════════════════════════════════════════════════════╗"<<endl;
    cout << "   ║" << centrar("TENES "+ to_string(dados_stock[jugador]) + " DADOS DISPONIBLES EN TU STOCK", 59) << "║"<<endl;
    cout << "   ╠═══════════════════════════════════════════════════════════╝"<<endl;
    cout << "   ║ ENTER! PARA LANZAR LOS DADOS...║"<<endl;
    cout << "   ╚════════════════════════════════╝";enter();
}


void mensaje_dados_seleccionados() {

    cout << "╔══════════════════════════════════════════╗"<<endl;
    cout << "║   ESTOS FUERON TUS DADOS SELECCIONADOS   ║"<<endl;
    cout << "╚══════════════════════════════════════════╝"<<endl;
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


void mostrar_dados_horizontal(int dados_stock[], int cant_dados_stock, bool mostra_posicion) {

    if (cant_dados_stock == 0) {
        cout <<"╔═══════╗"<<endl;
        cout <<"║   N   ║"<<endl;
        cout <<"║   A   ║"<<endl;
        cout <<"║   N   ║"<<endl;
        cout <<"╚═══════╝"<<endl;
    } else {

        for (int i = 0; i < cant_dados_stock; ++i)
            cout << "╔═══════╗  ";
        cout << endl;

        for (int i = 0; i < cant_dados_stock; ++i) {
            int d = dados_stock[i];
            if (d == 1) cout << "║       ║  ";
            else if (d == 2 || d == 3) cout << "║ *     ║  ";
            else if (d >= 4 && d <= 6) cout << "║ *   * ║  ";
        }
        cout << endl;

        for (int i = 0; i < cant_dados_stock; ++i) {
            int d = dados_stock[i];
            if (d == 1 || d == 3 || d == 5) cout << "║   *   ║  ";
            else if (d == 2 || d == 4) cout << "║       ║  ";
            else if (d == 6) cout << "║ *   * ║  ";
        }
        cout << endl;

        for (int i = 0; i < cant_dados_stock; ++i) {
            int d = dados_stock[i];
            if (d == 1) cout << "║       ║  ";
            else if (d == 2 || d == 3) cout << "║     * ║  ";
            else if (d >= 4 && d <= 6) cout << "║ *   * ║  ";
        }
        cout << endl;

        for (int i = 0; i < cant_dados_stock; ++i)
            cout << "╚═══════╝  ";
        cout << endl;

        if (mostra_posicion) {
            for (int i = 0; i < cant_dados_stock; ++i)
                cout << "  [ " << i + 1 << " ]    ";
            cout << endl;
        }
    }
}


void mensaje_gano_la_partida(int puntaje, int suma) {
    int ancho = 63;
    cout << "      ╔═════════════════════════════════════════════════════════╗"<<endl;
    cout << "      ║            FELICIDADES! HAS GANADO LA PARTIDA           ║"<<endl;
    cout << "   ╔══╝═════════════════════════════════════════════════════════╚═╗"<<endl;
    cout << "   ║" << centrar("PUNTAJE OBTENIDO FUE DE: "+to_string(puntaje)+ " PTS", ancho) << "║"<<endl;
    cout << "   ║" << centrar("LA SUMA DE LOS DADOS FUE: " + to_string(suma), ancho) << "║"<<endl;
    cout << "   ╠══════════════════════════════════════════════════════════════╝"<<endl;
    cout << "   ║ ENTER PARA CONTINUAR...║"<<endl;
    cout << "   ╚════════════════════════╝";enter();
    cout <<endl;
}


void mensaje_objetivo_cumplido(string nombres[], int jugador, int stock[], int usados, int suma, int puntaje) {
    int oponente = jugador ^ 1;
    const int ancho = 74;
    cout << endl;
    cout << "   ╔══════════════════════════════════════════════════════════════════════════╗"<<endl;
    cout << "   ║" << centrar("FELICIDADES! CUMPLISTE EL OBJETIVO", ancho) << "║"<<endl;
    cout << "   ╠══════════════════════════════════════════════════════════════════════════╣"<<endl;
    cout << "   ║" << centrar("TU PUNTAJE OBTENIDO FUE DE: "+to_string(puntaje)+" PTS", ancho) << "║"<<endl;
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
    cout << endl;
    cout << "   ╔══════════════════════════════════════════════════════════════════════════╗"<<endl;
    cout << "   ║" << centrar("LO SIENTO, NO CUMPLISTE EL OBJETIVO", ancho) << "║"<<endl;
    cout << "   ╠══════════════════════════════════════════════════════════════════════════╣"<<endl;
    cout << "   ║" << centrar("TU PUNTAJE OBTENIDO FUE DE: O PTS", ancho) << "║"<<endl;
    cout << "   ║" << centrar("LA SUMA DE LOS DADOS FUE: " + to_string(suma), ancho) << "║"<<endl;
    cout << "   ║" << centrar(" SE TE PENALIZARA AGREGANDO UN DADO MAS A TU STOCK ", ancho) << "║"<<endl;
    cout << "   ║" << centrar(" AHORA TENDRAS EN TU STOCK " + to_string(cant_dados_stock[jugador]) + " DADOS", ancho) << "║"<<endl;
    cout << "   ╠══════════════════════════════════════════════════════════════════════════╝"<<endl;
    cout << "   ║ ENTER PARA CONTINUAR...║"<<endl;
    cout << "   ╚════════════════════════╝";enter();
    cout <<endl;
}


void mensaje_objetivo_no_cumplido_mas_stock_max( int cant_dados_stock[], int jugador,  int ronda, string nombre_jugador[], int suma) {
    const int ancho = 74;
    int oponente = jugador ^ 1;
    cout << endl;
    cout << "   ╔══════════════════════════════════════════════════════════════════════════╗"<<endl;
    cout << "   ║" << centrar("LO SIENTO, NO CUMPLISTE EL OBJETIVO", ancho) << "║"<<endl;
    cout << "   ╠══════════════════════════════════════════════════════════════════════════╣"<<endl;
    cout << "   ║" << centrar("PUNTAJE OBTENIDO FUE DE: O PTS", ancho) << "║"<<endl;
    cout << "   ║" << centrar("LA SUMA DE LOS DADOS FUE: " + to_string(suma), ancho) << "║"<<endl;
    cout << "   ║" << centrar("TE QUEDARAS CON LA MISMA CANTIDAD DE DADOS EN EL STOCK", ancho) << "║"<<endl;
    cout << "   ║" << centrar("PORQUE " + nombre_jugador[oponente] +" TIENE UN SOLO DADO", ancho) << "║"<<endl;
    cout << "   ╠══════════════════════════════════════════════════════════════════════════╝"<<endl;
    cout << "   ║ ENTER PARA CONTINUAR...║"<<endl;
    cout << "   ╚════════════════════════╝";enter();
    cout <<endl;
}



void credito() {
    cout << R"(
                   ╔══════════════════════════════════════════════╗
                   ║                  CREDITOS                    ║
    ╔══════════════╝══════════════════════════════════════════════╚════════════╗
    ║  JUEGO CREADO POR: ANGEL SIMON                                           ║
    ║  LEVEMENTE INSPIRADO EN EL JUEGO: "MAFIA"                                ║
    ╠══════════════════════════════════════════════════════════════════════════╣
    ║  RECURSOS UTILIZADOS: ▪ ICONOS DE FREEPIK                                ║
    ║                       ▪ LOGOTIPO DISEÑADO EN LOGO MAKER                  ║
    ╠══════════════════════════════════════════════════════════════════════════╣
    ║           EQUIPO DE DESARROLLO - "LOS DEL CODIGO SIN GARANTIAS"          ║
    ╠══════════════════════════════════════════════════════════════════════════╣
    ║    ▪ ULISES SERGIO MARTÍN AGUIRRE – LEGAJO: 32529                        ║
    ║    ▪ CRISTIAN NICOLÁS SÁNCHEZ     – LEGAJO: 32283                        ║
    ╠══════════════════════════════════════════════════════════════════════════╝
    ║ ENTER PARA VOLVER AL MENU PRINCIPAL...║
    ╚═══════════════════════════════════════╝)";enter();

}

void mostrar_ranking(string ranking_jugadores[], int ranking_puntajes[], int longitud_ranking) {

    cout << "   ╔═════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "   ║" << centrar("🏆 RANKING DE JUGADORES 🏆", 73) << "║" << endl;
    cout << "   ╠═════════════════════════════════════════════════════════════════════╣" << endl;
    cout << "   ║  Pos │        Nombre        │   Puntaje                             ║" << endl;
    cout << "   ╠══════╬══════════════════════╬═══════════════════════════════════════╣" << endl;

    for (int i = 0; i < longitud_ranking; i++) {
        if (ranking_jugadores[i] != "") {
            cout << "   ║  ";
            if (i + 1 < 10) cout << " "; 
            cout << i + 1 << "  │ ";
            cout << setw(20) << left << ranking_jugadores[i] << " │   ";
            cout << setw(36) << left << ranking_puntajes[i];
            cout << "║" << endl;
        }
    }

    cout << "   ╚═════════════════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
    enter();
}

