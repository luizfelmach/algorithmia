#include <bits/stdc++.h>

using namespace std;

// NOTEBOOK
// Algoritm to find Catalan's Number
//
// Analytical formula:
/*\[cat(n) = \frac{1}{n+1} \cdot \binom{2n}{n} = \frac{(2n)!}{n!(n+1)!}\]*/
// Recursive formula:
/*
\[
\text{cat}(0) = \text{cat}(1) = 1
\]
\[
\text{cat}(n) = \sum_{k=0}^{n-1} \text{cat}(k) \cdot \text{cat}(n-1-k) \quad
\text{for } n \geq 2
\]
*/

// 1. Cat(n) counts the number of distinct binary trees with n vertices, e.g.
// for n = 3:
//     *   *      *     *     *       cat(3) = 5
//    /   /      / \     \     \
//   *    *     *   *     *     *
//  /      \             /       \
// *        *            *        *

// 2. Cat(n) counts the number of expressions containing n pairs of parentheses
// which are correctly matched, e.g. for n = 3, we have: ()()(), ()(()), (())(),
// ((())), and (()()).

// 3. Cat(n) counts the number of different ways n + 1 factors can be completely
// parenthe-sized, e.g. for n = 3 and 3 + 1 = 4 factors: {a, b, c, d}, we have:
// (ab)(cd), a(b(cd)), ((ab)c)d, (a(bc))(d), and a((bc)d).

// 4. Cat(n) counts the number of ways a convex polygon of n + 2 sides can be
// triangulated using the diagonal. e.g. square 4 sides:
//
// |\  | |  /|  cat(2) = 2
// | \ | | / |
// |  \| |/  |

// 5. Cat(n) counts the number of monotonic paths along the edges of an n x n
// grid, which do not pass above the diagonal. A monotonic path is one which
// starts in the lower left corner, finishes in the upper right corner, and
// consists entirely of edges pointing rightwards or upwards.

int main() {
    int n = 20;

    int cat[1000];
    cat[0] = cat[1] = 1;  // Base cases

    for (int i = 2; i <= n; i++) {
        cat[i] = 0;
        for (int k = 0; k < i; k++) {
            cat[i] += cat[k] * cat[i - 1 - k];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << cat[i] << " ";
    }

    return 0;
}
// NOTEBOOK