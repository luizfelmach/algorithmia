#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef vector<int>        vi;

// NOTEBOOK
// Algorithm to find prime factors of a number

ull primes[] = {2, 3, 5, 7, 11, 13};  // This must be filled with sieve

vi prime_factors(ull N) {
    vi  factors;
    ull PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N) {
        while (N % PF == 0) {
            N /= PF;
            factors.push_back(PF);
        }
        PF = primes[++PF_idx];
    }
    if (N != 1) factors.push_back(N);
    return factors;
}
// NOTEBOOK

int main() {
    vi r = prime_factors(142391208960LL);

    for (auto i : r) {
        cout << i << " ";
    }
    cout << endl;

    r = prime_factors(13);

    for (auto i : r) {
        cout << i << " ";
    }
    cout << endl;

    r = prime_factors(20);

    for (auto i : r) {
        cout << i << " ";
    }
    cout << endl;
}