#include <bits/stdc++.h>
using namespace std;

typedef vector<int>    vi;
typedef pair<int, int> ii;

const int VMAX = 1000;

int        V;
vector<vi> adj;
vector<ii> bridges;
vi         articulation, parent, dfslow, dfsnum;  // VMAX
int        TIME, ROOT, CHILDREN;

void articulation_and_bridge(int s) {
    dfslow[s] = dfsnum[s] = ++TIME;
    for (auto a : adj[s]) {
        if (!dfsnum[a]) {
            parent[a] = s;
            if (s == ROOT) CHILDREN += 1;
            articulation_and_bridge(a);
            if (dfslow[a] >= dfsnum[s]) articulation[s] = true;
            if (dfslow[a] > dfsnum[s]) bridges.push_back({a, s});
            dfslow[s] = min(dfslow[s], dfslow[a]);
        } else if (a != parent[s])
            dfslow[s] = min(dfslow[s], dfsnum[a]);
    }
}

void find_articulation_and_bridge() {
    TIME         = 0;
    bridges      = vector<ii>(0);
    articulation = vi(V, 0);
    dfsnum       = vi(V, 0);
    dfslow       = vi(V, 0);
    parent       = vi(V, 0);
    for (int i = 0; i < V; i++) {
        if (!dfsnum[i]) {
            ROOT     = i;
            CHILDREN = 0;
            articulation_and_bridge(i);
            articulation[ROOT] = (CHILDREN > 1);
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

        find_articulation_and_bridge();

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