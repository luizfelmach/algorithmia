#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int t, n, g;
int p[1010], w[1010];
int dp[35][1010];

int solve(int cap, int obj) {
    if (cap < 0) return -INF;
    if (obj == n) return 0;
    if (cap == 0) return 0;

    int &ans = dp[cap][obj];
    if (ans != -1) return ans;

    int pega = p[obj] + solve(cap - w[obj], obj + 1);
    int passa = solve(cap, obj + 1);
    return ans = max(pega, passa);
}

int main() {
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> p[i] >> w[i];
        }
        int ans = 0;
        cin >> g;
        for (int i = 0; i < g; i++) {
            int mw;
            cin >> mw;
            ans += solve(mw, 0);
        }
        cout << ans << endl;
    }
    return 0;
}
