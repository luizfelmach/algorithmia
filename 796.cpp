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
            if (dfslow[a] > dfsnum[s])
                bridges.push_back({min(s, a), max(s, a)});
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
    while (cin >> V) {
        adj.assign(V, vi(0));

        for (int i = 0; i < V; i++) {
            char c;
            int  u, n;
            cin >> u;
            cin >> c;
            cin >> n;
            cin >> c;

            for (int j = 0; j < n; j++) {
                int v;
                cin >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        find_articulation_and_bridge();

        sort(begin(bridges), end(bridges));

        cout << bridges.size() << " critical links" << endl;

        for (auto [u, v] : bridges) {
            cout << u << " - " << v << endl;
        }
        cout << endl;

        //        for (auto v : adj) {
        //            for (auto u : v) {
        //                cout << u << " ";
        //            }
        //            cout << endl;
        //        }
        //        cout << endl << endl;
    }
    return 0;
}