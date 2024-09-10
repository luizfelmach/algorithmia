#include <iostream>

using namespace std;

int Z, I, M;

int next(int L) { return (Z * L + I) % M; }

int solve(int L) {
    int sol = 1;
    int tortoise = next(L);
    int hare = next(next(L));

    while (tortoise != hare) {
        tortoise = next(tortoise);
        hare = next(next(hare));
    }

    tortoise = next(L);

    while (tortoise != hare) {
        tortoise = next(tortoise);
        sol++;
    }

    return sol;
}

int main() {
    int k = 1;
    int L = 1;
    while (1) {
        cin >> Z >> I >> M >> L;
        if (L == 0 and Z == 0 and I == 0 and M == 0) {
            break;
        }
        cout << "Case " << k << ": " << solve(L) << endl;
        k++;
    }
    return 0;
}
