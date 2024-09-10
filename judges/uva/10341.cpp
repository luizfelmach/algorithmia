#include <bits/stdc++.h>

#define FLUT double

using namespace std;

int p, q, r, s, t, u;

FLUT f(FLUT x) {
    FLUT res = 0.0;
    res += p * exp(-x);
    res += q * sin(x);
    res += r * cos(x);
    res += s * tan(x);
    res += t * x * x;
    res += u;
    return res;
}

FLUT solve() {
    FLUT lo = 0.0;
    FLUT hi = 1.0;

    for (int i = 0; i < 100; i++) {
        FLUT mid = (lo + hi) / 2;

        FLUT r = f(mid);

        if (r > 0) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    return lo;
}

int main() {
    while (cin >> p >> q >> r >> s >> t >> u) {
        cout << setprecision(4) << fixed;
        FLUT result = solve();
        if (abs(f(result)) < 1e-7) {
            cout << result << endl;
        } else
            cout << "No solution" << endl;
    }
    return 0;
}
