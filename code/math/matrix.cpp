#include <bits/stdc++.h>

using namespace std;

typedef long long   ull;
typedef long double ld;

// NOTEBOOK
template <size_t R, size_t C>
using matrix = array<array<ull, C>, R>;

// Matrix Mulplitication
// Time complexity: /*$O(n^3)$*/
/*
\[
\text{A}_{m \times n} \cdot \text{B}_{n \times p} = \text{AB}_{m \times p}
\]
*/
template <size_t RA, size_t CA, size_t CB>
matrix<RA, CB> matrix_mult(matrix<RA, CA> a, matrix<CA, CB> b) {
    matrix<RA, CB> res = {};
    for (ull i = 0; i < RA; ++i)
        for (ull j = 0; j < CB; ++j)
            for (ull k = 0; k < CA; ++k) res[i][j] += a[i][k] * b[k][j];
    return res;
}

// Matrix Exponentiation
// Time complexity: /*$O(R^3 \cdot log(n))$*/
template <size_t R>
matrix<R, R> matrix_pow(matrix<R, R> m, ull n) {
    matrix<R, R> ans = {};
    for (ull i = 0; i < R; i++) ans[i][i] = 1;
    while (n) {
        if (n & 1) ans = matrix_mult(ans, m);
        m = matrix_mult(m, m);
        n >>= 1;
    }
    return ans;
}

// Find fibonacci's number from matrix
// Time complexity: /*$\approx O(log(n))$*/
/*
\[ \begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix} ^ n = \begin{bmatrix} F_{n+1} &
F_n \\ F_n & F_{n-1} \end{bmatrix} \]
*/
ull fibo(ull n) {
    matrix<2, 2> base{{
        {1, 1},
        {1, 0},
    }};
    return matrix_pow(base, n)[0][1];
}
// NOTEBOOK

int main() {
    for (ull i = 0; i < 91; i++) {
        cout << fibo(i) << endl;
    }
    return 0;
}
