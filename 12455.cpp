#include <iostream>

int n;
int p;
int bars[300];

using namespace std;

int solve(int cur, int soma) {
    if (cur > p) return 0;
    if (soma == n) return 1;
    if (soma > n) return 0;

    int pega  = solve(cur + 1, soma + bars[cur]);
    int passa = solve(cur + 1, soma);

    return pega || passa;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        cin >> p;
        for (int i = 0; i < p; i++) cin >> bars[i];
        int res = solve(0, 0);
        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
