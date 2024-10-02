#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef vector<int>        vi;

// NOTEBOOK
// Algorithm to find prime factors of a number
// And also some useful things from factorization
// Remember n = p1^a1 * p2^a2 * ... * pn ^ an
// map<ull, ull> means map<pn, an>

ull primes[] = {2, 3, 5, 7, 11, 13};  // This must be filled with sieve
// Factorization should not work if the number
// contains a prime that is not in this list

map<ull, ull> prime_factors(ull N) {
    map<ull, ull> factors;  // <pn, an>
    ull           PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N) {
        while (N % PF == 0) {
            N /= PF;
            factors[PF] += 1;
        }
        PF = primes[++PF_idx];
    }
    if (N != 1) factors[N] += 1;
    return factors;
}

ull count_prime_factors(map<ull, ull> factors) {
    ull result = 0;
    for (auto [p, a] : factors) {
        result += a;
    }
    return result;
}

ull num_divisors(map<ull, ull> factors) {
    ull result = 1;
    for (auto [p, a] : factors) {
        result *= (a + 1);
    }
    return result;
}

ull sum_divisors(map<ull, ull> factors) {
    ull result = 1;
    for (auto [p, a] : factors) {
        result *= ((ull)pow((double)p, a + 1.0) - 1) / (p - 1);
    }
    return result;
}

// Numbers a and b are coprime if gcd(a, b) = 1. Eulers totient function TOT(n)
// gives the number of coprime numbers to n between 1 and n. For example,
// TOT(12) = 4, because 1, 5, 7 and 11 are coprime to 12.
ull eulers_totient(ull N) {
    ull           result  = N;
    map<ull, ull> factors = prime_factors(N);
    for (auto [p, a] : factors) {
        result -= result / p;
    }
    return result;
}
// NOTEBOOK

void show_factors(map<ull, ull> factors) {
    int i = 0;
    for (auto [p, a] : factors) {
        cout << p << "^" << a;
        if (++i < factors.size()) cout << " * ";
    }
}

int main() {
    vector<ull> numbers = {142391208960ULL, 13, 30, 36, 1, 2, 3};

    for (auto i : numbers) {
        auto factors = prime_factors(i);
        cout << i << ": ";
        show_factors(factors);
        cout << endl;
        cout << "Count prime factors: " << count_prime_factors(factors) << endl;
        cout << "Total of divisors: " << num_divisors(factors) << endl;
        cout << "Sum of divisors: " << sum_divisors(factors) << endl;
        cout << "Eulers totient: " << eulers_totient(i) << endl;
        cout << endl;
    }
}