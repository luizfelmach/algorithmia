#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
long long memo[10010][23];

long long solve(long long amount, long long c = 1) {
    if (amount < 0) {
        return 0;
    }
    if (c == 22) return 0;
    if (amount == 0) {
        return 1;
    };
    long long &ans = memo[amount][c];
    if (ans != -1) return ans;

    long long pega_e_continua = solve(amount - pow(c, 3), c);
    long long passa = solve(amount, c + 1);

    return ans = passa + pega_e_continua;
}

int main() {
    long long amount;
    while (cin >> amount) {
        memset(memo, -1, sizeof(memo));
        cout << solve(amount) << endl;
    }
    return 0;
}
