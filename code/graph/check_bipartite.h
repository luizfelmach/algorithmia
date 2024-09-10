// Check if graph is bipartite

int        V;
vector<vi> adj;
int        color[VMAX];
bool       vis[VMAX];

int dfs(int s) {
    vis[s] = true;
    for (auto a : adj[s]) {
        if (color[a] == color[s]) return false;
        if (!vis[a]) {
            if (color[s] == 1)
                color[a] = 2;
            else
                color[a] = 1;
            if (!dfs(a)) return false;
        }
    }
    return true;
}

int bipartite() {
    for (int i = 0; i < V; i++) {
        vis[i]   = false;
        color[i] = 0;
    }
    for (int i = 0; i < V; i++)
        if (!vis[i]) {
            color[i] = 1;
            if (dfs(i)) return true;
        }
    return false;
}