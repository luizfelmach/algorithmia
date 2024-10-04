#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef vector<int>        vi;

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
// Naive check primality
// Time complexity: /*$O(\sqrt{n})$*/

bool is_prime(ull n) {
    if (n < 2) return false;
    for (ull x = 2; x * x <= n; x++)
        if (n % x == 0) return false;
    return true;
}
// Fermat primality test
// This is a probabilistic primality test.
// Time complexity: /*$O(k \cdot log(n))$*/
// This test use Fermat's Theorem: /*$a^{p-1} \equiv 1 \pmod{p}$*/
bool fermats_prime(int n, int k = 5) {
    if (n < 4) return n == 2 || n == 3;
    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 3);
        if (binpow(a, n - 1, n) != 1) return false;
    }
    return true;
}

// Miller-Rabin primality test
// This is also too probabilistic primality test.
// Time complexity: /*$O(k \cdot log(n))$*/
// This is an improvement on the Fermat test and is safer but slightly slower
bool check_composite(ull n, ull a, ull d, int s) {
    ull x = binpow(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1) return false;
    }
    return true;
}

bool miller_rabin_prime(ull n, int iter = 5) {
    if (n < 4) return n == 2 || n == 3;
    int s = 0;
    ull d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s)) return false;
    }
    return true;
}

// Primes < 1k
// .........................................................................
// :   2 :   3 :   5 :   7 :  11 :  13 :  17 :  19 :  23 :  29 :  31 :  37 :
// :  41 :  43 :  47 :  53 :  59 :  61 :  67 :  71 :  73 :  79 :  83 :  89 :
// :  97 : 101 : 103 : 107 : 109 : 113 : 127 : 131 : 137 : 139 : 149 : 151 :
// : 157 : 163 : 167 : 173 : 179 : 181 : 191 : 193 : 197 : 199 : 211 : 223 :
// : 227 : 229 : 233 : 239 : 241 : 251 : 257 : 263 : 269 : 271 : 277 : 281 :
// : 283 : 293 : 307 : 311 : 313 : 317 : 331 : 337 : 347 : 349 : 353 : 359 :
// : 367 : 373 : 379 : 383 : 389 : 397 : 401 : 409 : 419 : 421 : 431 : 433 :
// : 439 : 443 : 449 : 457 : 461 : 463 : 467 : 479 : 487 : 491 : 499 : 503 :
// : 509 : 521 : 523 : 541 : 547 : 557 : 563 : 569 : 571 : 577 : 587 : 593 :
// : 599 : 601 : 607 : 613 : 617 : 619 : 631 : 641 : 643 : 647 : 653 : 659 :
// : 661 : 673 : 677 : 683 : 691 : 701 : 709 : 719 : 727 : 733 : 739 : 743 :
// : 751 : 757 : 761 : 769 : 773 : 787 : 797 : 809 : 811 : 821 : 823 : 827 :
// : 829 : 839 : 853 : 857 : 859 : 863 : 877 : 881 : 883 : 887 : 907 : 911 :
// : 919 : 929 : 937 : 941 : 947 : 953 : 967 : 971 : 977 : 983 : 991 : 997 :
// :.....:.....:.....:.....:.....:.....:.....:.....:.....:.....:.....:.....:
// NOTEBOOK

// To generate ascii table: https://ozh.github.io/ascii-tables/

int main() {
    vi  primes;
    int count = 0;
    for (int i = 1; i < 1000; i++) {
        if (is_prime(i)) primes.push_back(i);
    }

    for (auto i : primes) {
        if (count % 12 == 0) cout << endl;
        cout << i << " ";
        count++;
    }

    return 0;
}