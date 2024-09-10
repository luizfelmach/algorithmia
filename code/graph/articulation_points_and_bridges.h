// Find articulations and bridges in an undirected graph
// Articulation is a vertex that, if removed, increases the number of connected
// components. Bridge is an edge that if removed the number of connected
// components increases.

int        V;
vector<vi> adj;
vector<ii> bridges;
vi         articulation, parent, dfslow, dfsnum;
int        TIME, ROOT, CHILDREN;

void dfs(int s) {
    dfslow[s] = dfsnum[s] = ++TIME;
    for (auto a : adj[s]) {
        if (!dfsnum[a]) {
            parent[a] = s;
            if (s == ROOT) CHILDREN += 1;
            dfs(a);
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
            dfs(i);
            articulation[ROOT] = (CHILDREN > 1);
        }
    }
}