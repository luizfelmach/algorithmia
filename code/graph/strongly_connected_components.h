// Tarjan's Algorithm
// Finding strongly connected components (Directed Graph)

int        V;
vector<vi> adj;
vi         dfslow, dfsnum;
bool       vis[VMAX];
int        SCC, TIME;
stack<int> aux;

void tarjan_dfs(int s) {
    dfslow[s] = dfsnum[s] = ++TIME;
    aux.push(s);
    vis[s] = true;
    for (auto a : adj[s]) {
        if (!dfsnum[a]) tarjan_dfs(a);
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
        if (!dfsnum[i]) tarjan_dfs(i);
    }
}