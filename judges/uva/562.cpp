#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, expec;
int coins[110];
int dp[50010][110];

int solve(int cap, int c) {
    if (cap < 0) return -INF;
    if (c == m) return 0;

    int &pdm = dp[cap][c];
    if (pdm != -1) return pdm;

    int pega = coins[c] + solve(cap - coins[c], c + 1);
    int passa = solve(cap, c + 1);

    return pdm = max(pega, passa);
}

int main() {
    cin >> n;
    while (n--) {
        expec = 0;
        memset(dp, -1, sizeof(dp));
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> coins[i];
            expec += coins[i];
        }
        cout << expec - 2 * solve(expec / 2, 0) << endl;
    }
    return 0;
}
