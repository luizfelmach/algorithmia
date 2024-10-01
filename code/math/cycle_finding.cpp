#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int f(int x) {
    return 0;
}

// NOTEBOOK
// Floyds Cycle-Finding Algorithm
//
// Time complexity:
//     O(mu + lambda)
//
// INPUT
//     - function f, f: S -> S
//                  Maps a number in set S to another
//                  number in the same set.
//     - x0, start position
//
// OUTPUT
//     - mu, start of cycle in f
//     - lambda, cycle length in f

ii floyd_cycle_finding(int x0) {
    int tortoise = f(x0);
    int hare     = f(f(x0));
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare     = f(f(hare));
    }
    int mu = 0;
    hare   = x0;
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare     = f(hare);
        mu++;
    }
    int lambda = 1;
    hare       = f(tortoise);
    while (tortoise != hare) {
        hare = f(hare);
        lambda++;
    }
    return ii(mu, lambda);
}
// NOTEBOOK