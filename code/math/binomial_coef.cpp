#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100;

// NOTEBOOK
// Analytical formula causes overflow for large numbers and maybe slower for
// biginteger.
/*\[\binom{n}{k} = \frac{n!}{k!(n-k)!}\]*/

// Its use dynamic programming to avoid number overflow.
// Recursive formula
/*\[\binom{n}{o} = \binom{n}{n} = 1, \text{base cases}\]*/
/*\[\binom{n}{k} = \binom{n-1}{k-1} + \binom{n-1}{k}, 0<k<n \]*/

// Time complexity to build matrix: /*$O(n^2)$*/

int coef[NMAX][NMAX];

void binomial_coef(int n) {
    coef[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        coef[i][0] = coef[i][i] = 1;
        for (int j = 1; j < n; j++) {
            coef[i][j] = coef[i - 1][j - 1] + coef[i - 1][j];
        }
    }
}
// Pascal's Triangle n = 0 to 15
//                                1
//                               1 1
//                              1 2 1
//                             1+3+3+1 /*$\sum_{k=0}^{n}\binom{n}{k} = 2^n$*/
//                            1 4 6 4 1
//                          1 5 10 10 5 1
//                        1 6 15 20 15 6 1
//                       1 7 21 35 35 21 7 1
//                     1 8 28 56 70 56 28 8 1
//                   1 9 36 84 126 126 84 36 9 1
//               1 10 45 120 210 252 210 120 45 10 1
//             1 11 55 165 330 462 462 330 165 55 11 1
//           1 12 66 220 495 792 924 792 495 220 66 12 1
//       1 13 78 286 715 1287 1716 1716 1287 715 286 78 13 1
//   1 14 91 364 1001 2002 3003 3432 3003 2002 1001 364 91 14 1
// 1 15 105 455 1365 3003 5005 6435 6435 5005 3003 1365 455 105 15 1
// NOTEBOOK

int main() {
    memset(coef, 0, sizeof(coef));
    int n;
    cin >> n;
    binomial_coef(n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << coef[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}