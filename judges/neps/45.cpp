// Torre
// https://neps.academy/br/exercise/45
// 571137 Torre C++ Accepted 100 20:40:48 21/07/2022

#include <iostream>
using namespace std;

int n;
int tab[1010][1010];
int somaLinha[1010];
int somaColuna[1010];

int maior() {
    int soma = 0;

    for(int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            s += tab[i][j];
        }
        somaLinha[i] = s;
    }

    for(int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            s += tab[j][i];
        }
        somaColuna[i] = s;
    }

    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s += somaLinha[i] + somaColuna[j];
            s -= 2 * tab[i][j];
            soma = max(soma, s);
            s = 0;
        }
    }

    return soma;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> tab[i][j];

    cout << maior() << endl;
    return 0;
}
