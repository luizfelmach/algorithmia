#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// NOTEBOOK
// Modular Exponentiation (/*$ x^n \mod m $*/)
// Time complexity /*$O(log(n))$*/

ull modpow(ull x, ull n, ull m) {
    if (n == 0) return 1 % m;
    ull u = modpow(x, n / 2, m);
    return ((u % m) * (u % m) * (n % 2 ? x % m : 1)) % m;
}

// Binary Exponentiation
ull binpow(ull x, ull n, ull m) {
    x %= m;
    ull res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}

// NOTEBOOK

int main() {
    cout << modpow(321, 34, 97) << endl;
    cout << binpow(321, 34, 97) << endl;
    return 0;
}
