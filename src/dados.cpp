#include "dados.h"
#include <cstdlib>
#include <ctime>
int tirar_dado(int caras) {
    return rand() % caras + 1;
}

void tirar_dados(int dados[], int cantidad, int caras) {
    for (int i = 0; i < cantidad; ++i) {
        dados[i] = tirar_dado(caras);
    }
}