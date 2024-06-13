#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll coins[] = {1, 5, 10, 25, 50};
ll t_coins = 5;
ll dp[30010][6];

ll solve(ll amount, ll c = 0) {
    if (c == t_coins) return 0;
    if (amount < 0) return 0;
    if (amount == 0) return 1;

    ll &ans = dp[amount][c];
    if (ans != -1) return ans;

    ll pega = solve(amount - coins[c], c);
    ll passa = solve(amount, c + 1);
    return ans = pega + passa;
}

int main() {
    ll amount;
    memset(dp, -1, sizeof(dp));
    while (cin >> amount) {
        ll result = solve(amount);
        if (result == 1) {
            cout << "There is only 1 way to produce ";
            cout << amount;
            cout << " cents change.";
        } else {
            cout << "There are ";
            cout << result;
            cout << " ways to produce ";
            cout << amount;
            cout << " cents change.";
        }
        cout << endl;
    }
    return 0;
}
