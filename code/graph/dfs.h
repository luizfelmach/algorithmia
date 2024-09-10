// Depth first search

int        V;
vector<vi> adj;
bool       vis[VMAX];
vi         topsort;  // Topological Sort.
                     // Only works in directed acyclic graph.

void dfs(int s) {
    vis[s] = true;
    for (auto a : adj[s]) {
        if (!vis[a]) {
            dfs(a);
        }
    }
    topsort.push_back(s);  // Only works in DAG.
}