// Fuga com Helicóptero
// https://neps.academy/br/exercise/5
// 569750 Fuga com Helicóptero C++ Accepted 100 18:55:30 18/07/2022

#include <iostream>
#include <cstring>

#define POLICIAL 1
#define FUGITIVO 2
#define HELICOPTERO 3

using namespace std;

int main() {
    int caminho[16];
    memset(caminho, 0, sizeof caminho);

    int H, P, F, D;
    cin >> H >> P >> F >> D;
    caminho[H] = HELICOPTERO;
    caminho[P] = POLICIAL;
    caminho[F] = FUGITIVO;

    bool achou;
    int cur =  F;

    while(true) {
        if (cur < 0) cur = 15;
        if (cur > 15) cur = 0;
        if (caminho[cur] == HELICOPTERO) {
            achou = true;
            break;
        }
        if (caminho[cur] == POLICIAL) {
            achou = false;
            break;
        }
        cur += D;
    }

    cout << (achou ? "S" : "N") << endl;

    return 0;
}
