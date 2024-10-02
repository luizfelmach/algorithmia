#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef vector<int>        vi;

// NOTEBOOK
// Sieve of Eratosthenes
// After building the sieve, checking whether a number is prime for N <=
// sieve_size is O(1). If N is larger sieve_size then it only works for N <
// largest squared prime number found in the sieve and it is slower
//
// Time complexity to build the sieve
//       O(Nlog(log(n)))
//
// INPUT
//     - N, number to check primality
//
// OUTPUT
//      - 1 if N is prime, 0 otherwise

ull              _sieve_size;
bitset<10000010> bs;  // 10^7 should be enough for most cases
vi               primes;

void sieve(ull upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ull i = 2; i <= _sieve_size; i++)
        if (bs[i]) {
            for (ull j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i);
        }
}

bool is_prime(ull N) {
    if (N <= _sieve_size) return bs[N];
    for (auto i : primes)
        if (N % i == 0) return false;
    return true;  // note: only work for N <= (last prime in vi "primes")^2
}
// NOTEBOOK

int main() {
    sieve(10000000);
    cout << is_prime(2147483647) << endl;       // Prime
    cout << is_prime(136117223861ULL) << endl;  // Not a prime, 104729*1299709
    return 0;
}
