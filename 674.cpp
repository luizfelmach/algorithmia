#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll coins[] = {1, 5, 10, 25, 50};
ll t_coins = 5;
ll dp[10000][6];

ll solve(ll amount, ll c = 0) {
    if (amount < 0) return 0;
    if (c == t_coins) return 0;
    if (amount == 0) return 1;

    ll &ans = dp[amount][c];
    if (ans != -1) return ans;

    ll pega_e_continua = solve(amount - coins[c], c);
    ll passa = solve(amount, c + 1);

    return ans = pega_e_continua + passa;
}

int main() {
    ll amount;
    memset(dp, -1, sizeof(dp));
    while (cin >> amount) {
        cout << solve(amount) << endl;
    }

    return 0;
}
