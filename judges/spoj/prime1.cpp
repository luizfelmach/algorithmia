// PRIME1 - Prime Generator
// https://www.spoj.com/problems/PRIME1/

#include <iostream>
using namespace std;
#define ll long long

bool isPrime(ll c) {
    bool isP = true;
    if (c == 2) return true;
    if (c == 1) return false;
    for (ll i = 2; i*i <= c; i++) {
        if (c % i == 0) return false;
    }
    return isP;
}

int main() {
    int n; cin >> n;
    while(n--) {
        ll n, m; cin >> n >> m;
        for(;n <=m;n++) {
            if (isPrime(n)) {
                cout << n << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
