#include <bits/stdc++.h>

using namespace std;

int                                    t, n;
int                                    nums[30];
set<vector<int>, greater<vector<int>>> resp;

void solve(int cur, int soma, vector<int> v) {
    if (cur > n) return;
    if (soma == t) {
        resp.insert(v);
        return;
    }
    if (soma > t) return;

    v.push_back(nums[cur]);
    solve(cur + 1, soma + nums[cur], v);
    v.pop_back();
    solve(cur + 1, soma, v);
}

int main() {
    for (;;) {
        resp.clear();
        cin >> t >> n;
        if (!t) break;

        cout << "Sums of " << t << ":" << endl;
        for (int i = 0; i < n; i++) cin >> nums[i];

        vector<int> r;
        solve(0, 0, r);

        if (resp.size() == 0) cout << "NONE" << endl;
        for (auto s : resp) {
            int count = 0;
            for (auto i : s) {
                cout << i;
                if (count < s.size() - 1) cout << "+";
                count++;
            }
            cout << endl;
        }
    }
    return 0;
}
