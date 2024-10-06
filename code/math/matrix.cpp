#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

// NOTEBOOK
template <size_t R, size_t C>
using matrix = array<array<double, C>, R>;

////////////////
// Matrix (+) //
////////////////
template <size_t R, size_t C>
matrix<R, C> operator+(matrix<R, C> a, matrix<R, C> b) {
    matrix<R, C> mat = {};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) mat[i][j] = a[i][j] + b[i][j];
    }
    return mat;
}

////////////////
// Matrix (*) //
////////////////
template <size_t R, size_t C>
matrix<R, C> operator*(double k, matrix<R, C> a) {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) a[i][j] *= k;
    return a;
}

////////////////
// Matrix (-) //
////////////////
template <size_t R, size_t C>
matrix<R, C> operator-(matrix<R, C> a, matrix<R, C> b) {
    return a + ((-1.0) * b);
}

/////////////////
// Show matrix //
/////////////////
template <size_t N, size_t C>
ostream& operator<<(ostream& os, matrix<N, C> a) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < C; j++) os << a[i][j] << " ";
        os << endl;
    }
    return os;
}

///////////////
// Matrix ID //
///////////////
template <size_t N>
matrix<N, N> id() {
    matrix<N, N> mat = {};
    for (int i = 0; i < N; i++) mat[i][i] = 1;
    return mat;
}

//////////////////
// Matrix (A*B) //
//////////////////
// Time complexity: /*$O(m \cdot n \cdot p)$*/
template <size_t M, size_t N, size_t P>
matrix<M, P> operator*(matrix<M, N> a, matrix<N, P> b) {
    matrix<M, P> res = {};
    for (ull i = 0; i < M; ++i)
        for (ull j = 0; j < P; ++j)
            for (ull k = 0; k < N; ++k) res[i][j] += a[i][k] * b[k][j];
    return res;
}

//////////////////
// Matrix (A^n) //
//////////////////
// Time complexity: /*$O(N^3 \cdot log(n))$*/
template <size_t N>
matrix<N, N> operator^(matrix<N, N> base, ull n) {
    matrix<N, N> ans = id<N>();
    while (n) {
        if (n & 1) ans = ans * base;
        base = base * base;
        n >>= 1;
    }
    return ans;
}

///////////////
// Fibonacci //
///////////////
// Time complexity: /*$\approx O(log(n))$*/
/*
\[ \begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix} ^ n = \begin{bmatrix} F_{n+1} &
F_n \\ F_n & F_{n-1} \end{bmatrix} \]
*/
ull fibo(ull n) {
    matrix<2, 2> base{{{1, 1}, {1, 0}}};
    return ((base ^ n)[1][0]);
}
// NOTEBOOK

int main() {
    for (ull i = 0; i < 91; i++) {
        cout << fibo(i) << endl;
    }

    matrix<2, 2> sq = {{{2, 4}, {1, 4}}};
    matrix<2, 3> a  = {{{1, 2, 3}, {4, 5, 6}}};
    matrix<2, 3> b  = {{{6, 5, 4}, {3, 2, 1}}};

    cout << (a + b) << endl;
    cout << (b - a) << endl;
    cout << (sq ^ 3) << endl;
    cout << (sq * sq * sq) << endl;

    return 0;
}
