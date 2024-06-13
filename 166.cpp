#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 0x3f3f3f3f;

ll coins[] = {5, 10, 20, 50, 100, 200};
ll t_coins = 6;
ll disp[] = {0, 0, 0, 0, 0, 0};

ll dp1[510][10];
ll dp2[510][10];

ll solve1(ll amount, ll c) {
    if (c == t_coins) return INF;
    if (amount < 0) return INF;
    if (amount == 0) return 0;
    ll &ans = dp1[amount][c];
    if (ans != -1) return ans;
    ll pega = 1 + solve1(amount - coins[c], c);
    ll passa = solve1(amount, c + 1);
    return ans = min(pega, passa);
}

ll solve2(ll amount, ll c) {
    if (c == t_coins) return INF;
    if (amount < 0) {
        return solve1(abs(amount), 0);
    }
    if (amount == 0) {
        return 0;
    }
    ll &ans = dp2[amount][c];
    if (ans != -1) return ans;

    int result = 0;
    if (disp[c] <= 0) {
        return ans = solve2(amount, c + 1);
    }
    disp[c] -= 1;
    ll pega = 1 + solve2(amount - coins[c], c);
    disp[c] += 1;
    ll passa = solve2(amount, c + 1);
    return ans = min(pega, passa);
}

int main() {
    while (1) {
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        for (int i = 0; i < t_coins; i++) cin >> disp[i];
        int flag = 0;
        for (int i = 0; i < t_coins; i++) flag += disp[i];
        if (!flag) break;
        double read;
        cin >> read;
        double amount = round(read * 100);
        cout << setw(3) << right << solve2(amount, 0) << endl;
    }
    return 0;
}
