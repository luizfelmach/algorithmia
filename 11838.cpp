#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

#define VMAX 100000

typedef vector<int> vi;

int        V;
vector<vi> adj;
vi         dfslow, dfsnum;
bool       vis[VMAX];
int        SCC, TIME;
stack<int> aux;

void tarjan_scc(int s) {
    dfslow[s] = dfsnum[s] = ++TIME;
    aux.push(s);
    vis[s] = 1;

    for (auto a : adj[s]) {
        if (!dfsnum[a]) tarjan_scc(a);
        if (vis[a]) dfslow[s] = min(dfslow[s], dfslow[a]);
    }

    if (dfslow[s] == dfsnum[s]) {
        SCC += 1;
        while (1) {
            int v = aux.top();
            aux.pop();
            vis[v] = 0;
            if (s == v) break;
        }
    }
}

void scc() {
    aux    = stack<int>();
    dfslow = vi(V, 0);
    dfsnum = vi(V, 0);
    memset(vis, false, sizeof(vis));
    TIME = SCC = 0;
    for (int i = 0; i < V; i++) {
        if (!dfsnum[i]) tarjan_scc(i);
    }
}

int main() {
    while (1) {
        int m;
        cin >> V >> m;

        adj.assign(V, vi(0));

        if (V == 0 and m == 0) break;

        for (int i = 0; i < m; i++) {
            int v, w, p;
            cin >> v >> w >> p;
            v -= 1;
            w -= 1;
            adj[v].push_back(w);
            if (p == 2) adj[w].push_back(v);
        }

        scc();

        if (SCC == 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
