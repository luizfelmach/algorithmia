#include <bits/stdc++.h>

using namespace std;

int next(int k) {
    int res = 0;
    int v;
    while (k != 0) {
        v = k % 10;
        res += pow(v, 2);
        k /= 10;
    }
    return res;
}

int isHappyNumber(int k) {
    if (k == 1) return 1;
    int res = 2;

    int tortoise = next(k);
    int hare = next(next(k));

    while (tortoise != hare) {
        tortoise = next(tortoise);
        hare = next(next(hare));
        res++;
    }

    if (tortoise != 1) return 0;

    return res;
}

int main() {
    int H, L, i;
    int t = 1;
    while (cin >> H >> L) {
        (!t) && cout << endl;
        for (i = H; i <= L; i++) {
            int res = isHappyNumber(i);
            if (res) {
                cout << i << " " << res << endl;
            }
        }
        t = 0;
    }
    return 0;
}
