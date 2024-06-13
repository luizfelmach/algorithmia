#include <cmath>
#include <cstring>
#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;

long long coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long dp[32000][13];
long long t_coins = 11;

long long solve(long long amount, long long c = 0) {
    if (amount < 0) return 0;
    if (c == t_coins) return 0;
    if (amount == 0) return 1;

    long long &ans = dp[amount][c];
    if (ans != -1) return ans;

    long long pega_e_continua = solve(amount - coins[c], c);
    long long passa = solve(amount, c + 1);

    return ans = pega_e_continua + passa;
}

int main() {
    double amount;
    memset(dp, -1, sizeof(dp));
    cout << setprecision(2) << fixed;
    while (1) {
        cin >> amount;
        if (amount == 0.0) break;
        long long value = round(amount * 100);
        cout << setw(6) << right << amount << setw(17) << right << solve(value)
             << endl;
    }
    return 0;
}
