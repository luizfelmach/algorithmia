// B. Ilya and Queries
// https://codeforces.com/contest/313/problem/B
// 165249734	Jul/21/2022 22:22UTC-3	luizfelmach	B - Ilya and Queries	GNU C++14	Accepted	1092 ms	600 KB

#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int n; cin >> n;
    int calc[s.size()];

    int cont = 0;
    for (int i = 0; i < s.size() -1; i++) {
        if (s[i] == s[i+1])
            cont++;
        calc[i] = cont;
    }
    // #..###
    // 01123

    while(n--) {
        int a, b; cin >> a >> b;
        int i;
        int f = calc[b-2];
        if (a == 1) {
            i = 0;
        } else {
            i = calc[a-2];

        }
        int soma = f - i;
        cout << soma << endl;
    }
    return 0;
}
