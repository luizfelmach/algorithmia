#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

#define VMAX 100000

typedef vector<int> vi;

int        V;
vector<vi> adj;
bool       vis[VMAX];
int        dfslow[VMAX];
int        dfsnum[VMAX];
int        scc_counter;
int        dfs_counter;
stack<int> aux;

void tarjan_scc(int s) {
    dfslow[s] = dfsnum[s] = dfs_counter++;
    aux.push(s);
    vis[s] = 1;

    for (auto a : adj[s]) {
        if (!dfsnum[a]) tarjan_scc(a);
        if (vis[a]) dfslow[s] = min(dfslow[s], dfslow[a]);
    }

    if (dfslow[s] == dfsnum[s]) {
        scc_counter += 1;
        while (1) {
            int v = aux.top();
            aux.pop();
            vis[v] = 0;
            if (s == v) break;
        }
    }
}

void scc() {
    memset(dfsnum, 0, sizeof(dfsnum));
    memset(dfslow, 0, sizeof(dfslow));
    memset(vis, false, sizeof(vis));
    while (!aux.empty()) aux.pop();
    dfs_counter = scc_counter = 0;
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

        if (scc_counter == 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
