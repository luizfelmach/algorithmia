// A. Collecting Beats is Fun
// https://codeforces.com/contest/373/problem/A
// 165421776	Jul/23/2022 08:59UTC-3	luizfelmach	A - Collecting Beats is Fun	GNU C++14	Accepted	15 ms	0 KB

#include <iostream>
using namespace std;

int main() {
    int k; cin >> k;
    int painel[16];

    for (int i = 0; i < 16; i++) {
        char a; cin >> a;
        if (a == '.') painel[i] = 0;
        else painel[i] = a - '0';
    }

    for (int tempo = 1; tempo < 10; tempo++) {
        for (int qtd = 0; qtd < k * 2; qtd++) {
            for (int i = 0; i < 16; i++) {
                if (painel[i] == tempo) {
                    painel[i] = 0;
                    break;
                }
            }
        }
    }


    int cont = 0;

    for (int i = 0; i < 16; i++)
        cont += painel[i];

    if (!cont)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
