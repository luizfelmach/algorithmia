// B. Rectangles
// https://codeforces.com/contest/844/problem/B
// 165451002	Jul/23/2022 14:05UTC-3	luizfelmach	B - Rectangles	GNU C++14	Accepted	15 ms	0 KB


#include <iostream>
#include <cstring>
using namespace std;

long long memo[60][60];

long long comb(int c, int b) {
    if (b == 0 or b == c) {
        return 1;
    }
    long long& p = memo[c][b];

    if (p != -1) return p;

    return p = comb(c-1, b-1) + comb(c-1, b);
}


int main() {
    memset(memo, -1, sizeof memo);

    int l, c;
    cin >> l >> c;
    long long cont = 0;

    int tab[l][c];

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cin >> tab[i][j];
        }
    }

    for (int i = 0; i < l; i++) {
        int um = 0;
        int zero = 0;
        for (int j = 0; j < c; j++) {
            if(tab[i][j] == 0)
                zero += 1;
            else
                um += 1;
        }
        for (int k = 1; k <= um; k++) {
            cont += comb(um, k);
        }
        for (int k = 1; k <= zero; k++) {
            cont += comb(zero, k);
        }
    }

    for (int i = 0; i < c; i++) {
        int um = 0;
        int zero = 0;
        for (int j = 0; j < l; j++) {
            if(tab[j][i] == 0)
                zero += 1;
            else
                um += 1;
        }
        for (int k = 1; k <= um; k++) {
            cont += comb(um, k);
        }
        for (int k = 1; k <= zero; k++) {
            cont += comb(zero, k);
        }
    }

    cont -= l * c;

    cout << cont << endl;
    return 0;
}
