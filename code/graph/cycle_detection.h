// Cycle detection in an undirected graph

int        V;
vector<vi> adj;
int        parent[VMAX];
bool       vis[VMAX];

int dfs(int s) {
    vis[s] = true;
    for (auto a : adj[s]) {
        if (!vis[a]) {
            parent[a] = s;
            if (dfs(a)) return true;
        } else if (a != parent[s])
            return true;  // There is a cycle
    }
    return false;
}

int cycle() {
    for (int i = 0; i < V; i++) {
        vis[i]    = false;
        parent[i] = -1;
    }
    for (int i = 0; i < V; i++)
        if (!vis[i])
            if (dfs(i)) return true;
    return false;
}