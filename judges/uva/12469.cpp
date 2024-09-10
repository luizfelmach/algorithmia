#include <bits/stdc++.h>

using namespace std;

int table[1010][1010];

int main() {
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i <= n; i++) {
            table[0][i] = 0;
            table[1][i] = 1;
            table[2][i] = 1;
        }

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                table[i][j] = 0;
                for (int k = 1; k <= 2 * j; k++) {
                    if (i >= k && table[i - k][k] == 0) {
                        table[i][j] = 1;
                        break;
                    }
                }
            }
        }

        // for (int i = 0; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << table[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        bool result = true;

        for (int i = n - 1, j = 1; i >= 1; i--, j++) {
            // cout << i << " " << j << endl;
            result &= table[i][j];
        }

        if (result) cout << n << endl;
        // cout << "Roberto\n";
        // else
        // cout << "Alicia\n";
    }

    return 0;
}
