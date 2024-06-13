#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 0x3f3f3f3f;

ll n, price;
ll dp[10010][110];
ll dp2[10010][110];
ll coins[110];
vector<ll> resp;

ll solve(ll amount, ll c = 0) {
    if (amount <= 0) return 0;
    if (c == n) return INF;

    ll &ans = dp[amount][c];
    if (ans != -1) return ans;

    ll pega = coins[c] + solve(amount - coins[c], c + 1);
    ll passa = solve(amount, c + 1);

    return ans = min(pega, passa);
}

ll recover(ll amount, ll c = 0) {
    if (c == n) return 0;
    if (amount <= 0) return 0;

    ll &ans = dp2[amount][c];
    if (ans != -1) return ans;

    ll pega = coins[c] + solve(amount - coins[c], c + 1);
    ll passa = solve(amount, c + 1);

    if (pega == passa) {
        ll result1 = 1 + recover(amount - coins[c], c + 1);
        ll result2 = recover(amount, c + 1);
        return ans = min(result1, result2);
    }

    if (pega < passa) {
        return ans = 1 + recover(amount - coins[c], c + 1);
    }

    return ans = recover(amount, c + 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> price;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp));

        for (int i = 0; i < n; i++) cin >> coins[i];

        cout << solve(price) << " ";
        cout << recover(price) << endl;
        // cout << resp.size() << endl;
    }
    return 0;
}
