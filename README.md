# Algorithms

### Graph

```cpp
// Depth first search

void dfs(vector<vi> G, int s, bool vis[]) {
    vis[s] = true;
    for (auto a : G[s]) {
        if (!vis[a]) {
            dfs(G, a, vis);
        }
    }
}
```

```cpp
// Breadth first search

void bfs(vector<vi> G, int s, bool vis[]) {
    queue<int> f; // Stack -> DFS
    f.push(s);
    vis[s] = true;
    while (!f.empty()) {
        int v = f.front();
        f.pop();
        for (auto a : G[v]) {
            if (!vis[a]) {
                vis[a] = true;
                f.push(a);
            }
        }
    }
}
```

```cpp
// Dijkstra

vi dijkstra(vector<vii> G, int s) {
    vi dist(G.size(), INF);
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        for (auto u : G[v]) {
            if (dist[u.first] > dist[v] + u.second) {
                dist[u.first] = dist[v] + u.second;
                pq.push({dist[u.first], u.first});
            }
        }
    }
    return dist;
}
```

```cpp
// Floyd-Warshall
// v_size = number of vertices
// dist[i][j] = 0 <-> i = j
// dist[i][j] = dist[i][j] if exists edge to (i, j)
// dist[i][j] = INF if there is no edge to (i, j)

void floyd_warshall(vector<vi> dist, int v_size) {
    for (int k = 0; k < v_size; k++)
        for (int i = 0; i < v_size; i++)
            for (int j = 0; j < v_size; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] =  dist[i][k] + dist[k][j];

}
```

```cpp
// Bellman-Ford
// v_size = number of vertices
// typedef tuple<int, int, int> iii;

int bellman_ford(vector<iii> E, int v_size, int s) {
    vi dist(v_size, INF);
    dist[s] = 0;
    for (int i = 0; i < v_size -1; i++) {
        for (auto uv : E) {
            int u = get<0>(uv);
            int v = get<1>(uv);
            int w = get<2>(uv);
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (auto uv : E) {
        int u = get<0>(uv);
        int v = get<1>(uv);
        int w = get<2>(uv);
        if (dist[u] + w < dist[v]) {
            return 0; // Negative cycle
        }
    }
    return 1;
}
```
