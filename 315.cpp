#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int VMAX = 1000;

int        V;
vector<vi> adj;
int        parent[VMAX];
int        dfslow[VMAX];
int        dfsnum[VMAX];
int        articulation[VMAX];
int        bridge[VMAX][VMAX];
int        dfs_counter;
int        root_children;
int        dfs_root;

void articulation_and_bridge(int s) {
    dfslow[s] = dfsnum[s] = ++dfs_counter;
    for (auto a : adj[s]) {
        if (!dfsnum[a]) {
            parent[a] = s;
            if (s == dfs_root) root_children += 1;
            articulation_and_bridge(a);
            if (dfslow[a] >= dfsnum[s]) articulation[s] = true;
            if (dfslow[a] > dfsnum[s]) bridge[s][a] = true;
            dfslow[s] = min(dfslow[s], dfslow[a]);
        } else if (a != parent[s])
            dfslow[s] = min(dfslow[s], dfsnum[a]);
    }
}

void AP() {
    dfs_counter = 0;
    memset(bridge, 0, sizeof(bridge));
    memset(articulation, 0, sizeof(articulation));
    memset(dfsnum, 0, sizeof(dfsnum));
    memset(dfslow, 0, sizeof(dfslow));
    memset(parent, 0, sizeof(parent));
    for (int i = 0; i < V; i++) {
        if (!dfsnum[i]) {
            dfs_root      = i;
            root_children = 0;
            articulation_and_bridge(i);
            articulation[dfs_root] = (root_children > 1);
        }
    }
}

int main() {
    while (1) {
        cin >> V;
        if (V == 0) break;

        adj.assign(V, vi(0));
        string P;
        getline(cin, P);

        while (1) {
            string line;
            getline(cin, line);
            // cout << "--" << line << endl;
            stringstream ss(line);
            int          u, v;
            ss >> u;
            if (u == 0) break;
            while (ss >> v) {
                adj[u - 1].push_back(v - 1);
                adj[v - 1].push_back(u - 1);
            }
        }

        AP();

        int res = 0;
        for (int i = 0; i < V; i++) {
            if (articulation[i]) res += 1;
        }

        cout << res << endl;

        // for (auto v : adj) {
        //     for (auto u : v) {
        //         cout << u << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl << endl;
    }
    return 0;
}