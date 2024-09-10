// A. Optimal Path
// https://codeforces.com/contest/1700/problem/A
// 163605614	Jul/10/2022 20:33UTC-3	luizfelmach	A - Optimal Path	GNU C++14	Accepted	15 ms	0 KB

#include <iostream>

using namespace std;

int main() {
    int qtd; cin >> qtd;
    long long n, m;
    long long soma = 0;

    while(qtd--) {
        cin >> n >> m;
        soma += m*(m+1)/2 + n*m*(n + 1)/2 -m;
        cout << soma << endl;
        soma = 0;
    }
    return 0;
}
