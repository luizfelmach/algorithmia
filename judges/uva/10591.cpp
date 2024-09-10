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
    int N, i, c;
    cin >> N;
    for (i = 1; i <= N; i++) {
        cin >> c;
        int res = isHappyNumber(c);
        if (res == 0)
            cout << "Case #" << i << ": " << c << " is an Unhappy number.\n";
        else
            cout << "Case #" << i << ": " << c << " is a Happy number.\n";
    }
    return 0;
}
