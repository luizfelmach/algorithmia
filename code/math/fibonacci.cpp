#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int NMAX = 1000;

// NOTEBOOK
// Golden Ratio (/*$\frac{1+\sqrt{5}}{2}$*/)
const double PHI = (1.0 + sqrt(5)) / 2.0;
ull          dp[NMAX];  // Memoization

// Fibonacci recursive
ull fibo(ull n) {
    if (n <= 1) return n;
    ull &ans = dp[n];  // Dynamic Programming
    if (ans != -1) return ans;
    return ans = fibo(n - 1) + fibo(n - 2);
}

// Fibonacci iterative
ull fibo_iter(ull n) {
    if (n <= 1) return n;
    ull a = 0, b = 1, temp;
    for (ull i = 2; i < n + 1; i++) {
        temp = a + b;
        a    = b;
        b    = temp;
    }
    return b;
}

// Binet's Formula (/*$\frac{\phi^n-(-\phi)^{-n}}{\sqrt{5}}$*/)
// Analytical formula to calculate nth fibonacci
// Works for /*$ n \leq 70$*/
// Time complexity: /*$O(1)$*/
ull fibo_appr(ull n) {
    double _n  = (double)n;
    double res = (pow(PHI, _n) - pow(-PHI, -_n)) / sqrt(5);
    return (ull)res;
}
// NOTEBOOK

int main() {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 80; i++) {
        ull f_real = fibo(i);
        ull f_iter = fibo_iter(i);
        ull f_appr = fibo_appr(i);
        if (f_real != f_appr) {
            cout << "fibo_appr(" << i << ") is wrong ";
        }
        cout << fibo(i) << " " << f_iter << " " << fibo_appr(i) << endl;
    }
    return 0;
}