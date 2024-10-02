#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// NOTEBOOK
// Modular Exponentiation
// Time complexity
//         O(log(n))

// (x^n) % m
ull modpow(ull x, ull n, ull m) {
    if (n == 0) return 1 % m;
    ull u = modpow(x, n / 2, m);
    return ((u % m) * (u % m) * (n % 2 ? x % m : 1)) % m;
}
// NOTEBOOK

int main() {
    cout << modpow(321, 34, 97) << endl;
    return 0;
}