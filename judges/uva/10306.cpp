#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 0x3f3f3f3f;

ll m, s;
ll conv_coins[50];
ll info_coins[50];
ll dp[301][301][41][41];

ll solve(ll a_cc, ll a_ic, ll cc, ll ic) {
    if (sqrt(a_cc * a_cc + a_ic * a_ic) == s) {
        return 0;
    }
    if (sqrt(a_cc * a_cc + a_ic * a_ic) > s) {
        return INF;
    }
    if (cc >= m || ic >= m) return INF;

    ll &ans = dp[a_cc][a_ic][cc][ic];
    // if (ans != -1) return ans;

    ll e1 = 1 + solve(a_cc + conv_coins[cc], a_ic + info_coins[ic], cc, ic);
    ll e2 = solve(a_cc, a_ic, cc + 1, ic + 1);

    return ans = min(e1, e2);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> m >> s;
        // memset(dp, -1, sizeof(dp));
        for (int i = 0; i < m; i++) cin >> conv_coins[i] >> info_coins[i];

        ll result = solve(0, 0, 0, 0);
        if (result >= INF)
            cout << "not possible" << endl;
        else
            cout << result << endl;
    }
    return 0;
}
