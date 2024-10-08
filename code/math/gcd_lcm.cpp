#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

// NOTEBOOK
// Time complexity: /*$O(\log(n)) \quad \text{where} \quad n = \max(a, b)$*/

// GCD and LCM of more than 2 numbers is
// equal to gcd(a, gcd(b, c)), lcm(a, lcm(b, c))

// Greatest common divisor
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Least common multiple
int lcm(int a, int b) {
    return a * (b / gcd(a, b));
}
// NOTEBOOK