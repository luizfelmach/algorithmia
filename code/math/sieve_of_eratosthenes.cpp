#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef vector<int>        vi;

// NOTEBOOK
// Sieve of Eratosthenes
// Once the sieve is built, checking if a number is prime for N <= _sieve_size
// takes O(1) time. For N > _sieve_size, the check remains valid only for
// numbers smaller than the square of the largest prime in the sieve, but the
// process becomes slower.

// Time complexity to build the sieve: /*$O(n \cdot log(log(n)) \approx O(n)$*/

ull              _sieve_size;
bitset<10000010> bs;  // /*$10^7$*/ should be enough for most cases
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
    return true;  // Only work for /*$N \leq (\text{last prime in vi})^2$*/
                  // For /*$10^7$*/ /*$N \leq (9999991)^2 = 99999820000081$*/
}
// NOTEBOOK

int main() {
    sieve(10000000);
    cout << is_prime(2147483647) << endl;       // Prime
    cout << is_prime(136117223861ULL) << endl;  // Not a prime, 104729*1299709
    cout << primes.back() << endl;
    return 0;
}
