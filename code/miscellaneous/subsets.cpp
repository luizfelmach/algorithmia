#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

// NOTEBOOK
// Generate all subsets with submaks
// Time complexity: /*$O(2^n)$*/

void subsets(ull n) {
    for (ull i = 0; i < 1LLU << n; i++) {
        for (ull k = 0; k < n; k++) {
            if (i & 1LLU << k)
                cout << "1";
            else
                cout << "0";
        }
        cout << endl;
    }
}
// NOTEBOOK

int main() {
    subsets(5);
    return 0;
}