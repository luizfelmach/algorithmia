// Breadth first search

int        V;
vector<vi> adj;
bool       vis[VMAX];
int        dist[VMAX];
int        parent[VMAX];

void bfs(int s) {
    queue<int> f;  // Stack -> DFS
    f.push(s);
    vis[s]    = true;
    parent[s] = -1;
    while (!f.empty()) {
        int v = f.front();
        f.pop();
        for (auto a : adj[v]) {
            if (!vis[a]) {
                vis[a]    = true;
                dist[a]   = dist[v] + 1;
                parent[a] = v;
                f.push(a);
            }
        }
    }
}