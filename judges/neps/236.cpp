// Quadrado Mágico (OBI 2007)
// https://neps.academy/br/exercise/236
// 571095 Quadrado Mágico (OBI 2007) C++ Accepted 100 19:23:48 21/07/2022

#include <iostream>
using namespace std;

int n;
int q[20][20];

int solve() {
    int soma = 0, novaSoma = 0;

    for (int i = 0; i < n; i++)
        soma += q[0][i];

    for (int i = n -1, j = 0; i >= 0; i--, j++)
        novaSoma += q[i][j];

    if (novaSoma != soma) return -1;

    novaSoma = 0;
    for (int i = 0; i < n; i++)
        novaSoma += q[i][i];

    if (novaSoma != soma) return -1;

    for (int i  = 0; i < n; i++) {
        novaSoma = 0;

        for (int j = 0; j < n; j++)
            novaSoma += q[i][j];

        if (novaSoma != soma) return -1;
    }

    for (int i  = 0; i < n; i++) {
        novaSoma = 0;

        for (int j = 0; j < n; j++)
            novaSoma += q[j][i];

        if (novaSoma != soma) return -1;
    }


    return soma;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> q[i][j];

    cout << solve() << endl;

    return 0;
}
