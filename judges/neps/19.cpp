// Botas Trocadas
// https://neps.academy/br/exercise/19
// 571116 Botas Trocadas C++ Accepted 100 19:47:17 21/07/2022

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> botas(70);
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        char pe;
        int numero;
        cin >> numero >> pe;

        if (pe == 'E')
            botas[numero].first += 1;
        else
            botas[numero].second += 1;
    }

    int cont = 0;

    for (auto bota : botas) {
        cont += min(bota.first, bota.second);
    }

    cout << cont << endl;

    return 0;
}
