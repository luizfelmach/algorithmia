#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100;

// NOTEBOOK
// Finding the coefficients of the algebraic expansion of powers of a binomial
// Its use dynamic programming to avoid number overflow
//
// Analytical function
// C n, k = n!/[(n-k)!k!] but this causes overflow for large numbers
//
// Time complexity
//         O(n^2)

int memo[NMAX][NMAX];

void binomial_coef(int n) {
    memo[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        memo[i][0] = memo[i][i] = 1;
        for (int j = 1; j < n; j++) {
            memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j];
        }
    }
}

int main() {
    memset(memo, 0, sizeof(memo));
    int n;
    cin >> n;
    binomial_coef(n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// NOTEBOOK