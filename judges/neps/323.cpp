// Desafio do Maior Número
// https://neps.academy/br/exercise/323
// 569727 Desafio do Maior Número C++ Accepted 100 16:53:26 18/07/2022

#include <iostream>

using namespace std;

int main() {
    int a, maior = 0;

    do {
        cin >> a;
        if (a > maior) maior = a;

    } while(a != 0);

    cout << maior << endl;

    return 0;
}
