#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef vector<int>        vi;

// NOTEBOOK
// Algorithm to find prime factors of a number

// Helpful variables produced through factorization

ull numPF;      // Count the number of prime factors of N
ull num_div;    // Count the number of divisors of N
ull sum_div;    // Sum the divisors of N
ull euler_phi;  // Number of coprimes from [1...N-1]
                // a, b are coprimes if gcd(a, b) = 1

ull primes[] = {2, 3, 5, 7, 11, 13};  // This must be filled with sieve

vi prime_factors(ull N) {
    vi  factors;
    ull PF_idx = 0, PF = primes[PF_idx];

    numPF     = 0;
    num_div   = 1;
    sum_div   = 1;
    euler_phi = N;

    while (PF * PF <= N) {
        ull power = 0;
        if (N % PF == 0) euler_phi -= euler_phi / PF;
        while (N % PF == 0) {
            N /= PF;
            factors.push_back(PF);
            power += 1;
            numPF += 1;
        }
        num_div *= (power + 1);
        sum_div *= ((ull)pow((double)PF, power + 1.0) - 1) / (PF - 1);
        PF = primes[++PF_idx];
    }
    if (N != 1) {
        factors.push_back(N);
        numPF += 1;
        num_div *= 2;
        sum_div *= ((ull)pow((double)N, 2.0) - 1) / (N - 1);
        euler_phi -= euler_phi / N;
    }
    return factors;
}
// NOTEBOOK

int main() {
    vi r = prime_factors(142391208960LL);

    for (auto i : r) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Count factors: " << numPF << endl;
    cout << "Count divs: " << num_div << endl;
    cout << "Sum divs: " << sum_div << endl;
    cout << "Coprimes: " << euler_phi << endl;
    cout << endl;

    r = prime_factors(13);

    for (auto i : r) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Count factors: " << numPF << endl;
    cout << "Count divs: " << num_div << endl;
    cout << "Sum divs: " << sum_div << endl;
    cout << "Coprimes: " << euler_phi << endl;
    cout << endl;

    r = prime_factors(60);

    for (auto i : r) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Count factors: " << numPF << endl;
    cout << "Count divs: " << num_div << endl;
    cout << "Sum divs: " << sum_div << endl;
    cout << "Coprimes: " << euler_phi << endl;
    cout << endl;

    r = prime_factors(36);

    for (auto i : r) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Count factors: " << numPF << endl;
    cout << "Count divs: " << num_div << endl;
    cout << "Sum divs: " << sum_div << endl;
    cout << "Coprimes: " << euler_phi << endl;
    cout << endl;
}