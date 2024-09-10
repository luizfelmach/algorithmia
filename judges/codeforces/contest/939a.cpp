// A. Love Triangle
// https://codeforces.com/contest/939/problem/A
// 161261074	Jun/19/2022 20:13UTC-3	luizfelmach	A - Love Triangle	GNU C++14	Accepted	31 ms	300 KB

#include <bits/stdc++.h>
using namespace std;

const int MAX = 5010;

bool triangle = false;
vector<int> adj[MAX];
bool vis[MAX];

bool solve(int s) {
    int a = adj[s][0];
    int b = adj[a][0];
    int c = adj[b][0];
    return c == s;
}


int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        adj[i].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (solve(i)) {
            cout << "YES" << endl;
            exit(0);
        }
    }

    cout << "NO" << endl;
}
