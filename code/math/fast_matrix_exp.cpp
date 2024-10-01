#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// NOTEBOOK
// Algorithm to perform quick exponentiation of square matrices
// Used to calculate the Fibonacci value using a special matrix
//
// Time complexity
//         O (m^3log(n))
//
// INPUT
//     - Square matrix (m x m)
//     - n, power value
//
// OUTPUT
//     - exponentiated matrix

template <size_t N>
using matrix = array<array<ull, N>, N>;  // Square matrix

template <size_t N>
matrix<N> matrix_id() {
    matrix<N> id = {};  // All elements are initialized to zero
    for (ull i = 0; i < N; i++) id[i][i] = 1;
    return id;
}

template <size_t N>
matrix<N> matrix_mult(matrix<N> a, matrix<N> b) {
    matrix<N> res = {};  // All elements are initialized to zero
    for (ull i = 0; i < N; i++) {
        for (ull j = 0; j < N; j++) {
            for (ull k = 0; k < N; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

template <size_t N>
matrix<N> matrix_exp(matrix<N> a, ull n) {
    if (n == 0) return matrix_id<N>();
    matrix<N> c = matrix_exp(a, n / 2);
    c           = matrix_mult(c, c);
    if (n % 2 != 0) c = matrix_mult(c, a);
    return c;
}

int main() {
    matrix<2> fibo;

    fibo[0][0] = 1;  // | 1 1 | ^ n
    fibo[1][0] = 1;  // | 1 0 |
    fibo[0][1] = 1;
    fibo[1][1] = 0;  // fibo[1][0] = fibo(n)

    for (int i = 0; i < 90; i++) {
        matrix<2> res = matrix_exp<2>(fibo, i);
        cout << "Fibo(" << i << ") = " << res[1][0] << endl;
    }

    return 0;
}
// NOTEBOOK
