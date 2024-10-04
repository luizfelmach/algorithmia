#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

// NOTEBOOK
// Linear Diophantine Equation
/*
\[ax + by = c\]
*/
// Solution
/*
\[
x = x_0 + k \cdot \frac{b}{g}
\]
\[
y = y_0 - k \cdot \frac{a}{g}
\]
*/

int x, y;

// Extended Euclid
int egcd(int a, int b) {  // eval x,y | ax + by = gcd(a,b)
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d  = egcd(b, a % b);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x      = x1;
    y      = y1;
    return d;
}

// Find any solution (x, y) for ax + by = c
bool any_solution(int a, int b, int c) {
    int d = egcd(abs(a), abs(b));
    if (c % d) {
        return false;
    }
    x *= c / d;
    y *= c / d;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}

// Find all solution (x, y) for ax + by = c
bool all_solution(int a, int b, int c) {
    int d = egcd(abs(a), abs(b));
    if (c % d) {
        return false;
    }
    x *= c / d;
    y *= c / d;

    for (int i = 0; i < 240; i++) {
        int x1 = x + (b * i) / d;
        int y1 = y - a * i / d;
        if (a < 0) x1 = -x1;
        if (b < 0) y1 = -y1;
        cout << x1 << " " << y1 << endl;
    }

    return true;
}
// NOTEBOOK

int main() {
    if (any_solution(512, 108, 100)) {
        cout << x << " " << y << endl;
    } else {
        cout << "No solution." << endl;
    }

    if (!all_solution(25, 18, 839)) {
        cout << "No solution." << endl;
    }

    return 0;
}