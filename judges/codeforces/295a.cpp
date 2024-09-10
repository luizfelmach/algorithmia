// A. Greg and Array
// https://codeforces.com/contest/295/problem/A
// 165527469	Jul/24/2022 10:31UTC-3	luizfelmach	A - Greg and Array	GNU C++14	Accepted	764 ms	5500 KB

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n, 0);
    vector<tuple<long long, long long , long long>> op(m);
    vector<long long> qtd_op(m+1, 0);
    vector<long long> w(m+1, 0);
    vector<long long> s(n+1, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++) {
        int l, r, d; cin >> l >> r >> d;
        op[i] = make_tuple(l, r, d);
    }

    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        qtd_op[x-1] += 1;
        qtd_op[y] += -1;
    }

    for (int i = 1; i < m+1; i++) {
        qtd_op[i] += qtd_op[i-1];
    }

    for (int i = 0; i < m; i++) {
        int d = get<2>(op[i]);
        w[i] = d * qtd_op[i];
    }

    for (int i = 0; i < m; i++) {
        int l = get<0>(op[i]);
        int r = get<1>(op[i]);
        int d = get<2>(op[i]);
        s[l - 1] += w[i];
        s[r] += -w[i];
    }

    for (int i = 1; i < n + 1; i++) {
        s[i] += s[i-1];
    }

    for (int i = 0; i < n; i++) {
        cout << (long long)(a[i] + s[i]) << " ";
    }
    cout << endl;

    return 0;
}

