// D. Bicycle Race
// https://codeforces.com/contest/659/problem/D
// 164820770	Jul/18/2022 18:33UTC-3	luizfelmach	D - Bicycle Race	GNU C++14	Accepted	15 ms	0 KB

#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

vector<pii> pontos;

bool subiu(pii pontoAtual, pii pontoAnterior) {

    int dx = pontoAtual.first - pontoAnterior.first;
    int dy = pontoAtual.second - pontoAnterior.second;

    return dx == 0 and dy > 0;
}

bool vaiParaEsquerda(pii pontoAtual, pii pontoPosterior) {

    int dx = pontoAtual.first - pontoPosterior.first;
    int dy = pontoAtual.second - pontoPosterior.second;

    return dy == 0 and dx > 0;
}

bool veioDaEsquerda(pii pontoAtual, pii pontoAnterior) {

    int dx = pontoAtual.first - pontoAnterior.first;
    int dy = pontoAtual.second - pontoAnterior.second;

    return dy == 0 and dx > 0;
}

bool vaiSubir(pii pontoAtual, pii pontoPosterior) {

    int dx = pontoAtual.first - pontoPosterior.first;
    int dy = pontoAtual.second - pontoPosterior.second;

    return dx == 0 and dy < 0;
}

bool veioDaDireita(pii pontoAtual, pii pontoAnterior) {

    int dx = pontoAtual.first - pontoAnterior.first;
    int dy = pontoAtual.second - pontoAnterior.second;

    return dy == 0 and dx < 0;
}

bool vaiDescer(pii pontoAtual, pii pontoPosterior) {

    int dx = pontoAtual.first - pontoPosterior.first;
    int dy = pontoAtual.second - pontoPosterior.second;

    return dx == 0 and dy > 0;
}

bool veioDeCima(pii pontoAtual, pii pontoAnterior) {

    int dx = pontoAtual.first - pontoAnterior.first;
    int dy = pontoAtual.second - pontoAnterior.second;

    return dx == 0 and dy < 0;
}

bool vaiParaDireita(pii pontoAtual, pii pontoPosterior) {

    int dx = pontoAtual.first - pontoPosterior.first;
    int dy = pontoAtual.second - pontoPosterior.second;

    return dy == 0 and dx < 0;
}

int main() {

    int qtd; cin >> qtd;
    qtd++;

    int x, y;
    while(qtd--) {
        cin >> x >> y;
        pontos.push_back(make_pair(x, y));
    }

    int cont = 0;

    for (int i = 1; i < pontos.size() - 1; i++) {
        pii pontoAtual = pontos[i];
        pii pontoAnterior = pontos[i-1];
        pii pontoPosterior = pontos[i+1];

        if (subiu(pontoAtual, pontoAnterior)) {
            if (vaiParaEsquerda(pontoAtual, pontoPosterior)) {
                cont++;
            }
        }
        if (veioDaEsquerda(pontoAtual, pontoAnterior)) {
            if (vaiSubir(pontoAtual, pontoPosterior)) {
                cont++;
            }
        }
        if (veioDaDireita(pontoAtual, pontoAnterior)) {
            if (vaiDescer(pontoAtual, pontoPosterior)) {
                cont++;
            }
        }
        if (veioDeCima(pontoAtual, pontoAnterior)) {
            if (vaiParaDireita(pontoAtual, pontoPosterior)) {
                cont++;
            }
        }
    }

    cout << cont << endl;

    return 0;
}
