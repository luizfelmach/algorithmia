#include <bits/stdc++.h>

using namespace std;

int next(int k) {
    int n = 4;
    int sq = k * k;
    sq /= 100;
    sq %= (int)pow(10, n);
    return sq;
}

int solve(int k) {
    int sol = 1;
    int tortoise = next(k);
    int hare = next(next(k));

    while (tortoise != hare) {
        tortoise = next(tortoise);
        hare = next(next(hare));
    }

    tortoise = k;

    while (tortoise != hare) {
        tortoise = next(tortoise);
        hare = next(hare);
        sol++;
    }

    tortoise = next(tortoise);
    while (tortoise != hare) {
        tortoise = next(tortoise);
        sol++;
    }

    return sol;
}

int main() {
    int a;
    while (1) {
        cin >> a;
        if (a == 0) break;
        cout << solve(a) << endl;
    }
    return 0;
}
