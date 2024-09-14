// NOTEBOOK
// Bellman-Ford

typedef tuple<int, int, int> iii;

int         V;
vector<iii> edges;  // <u, v, w>
int         dist[VMAX];

int bellman_ford(int s) {
    memset(dist, INF, sizeof(dist));
    dist[s] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (auto uv : edges) {
            auto [u, v, w] = uv;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (auto uv : edges) {
        auto [u, v, w] = uv;
        if (dist[u] + w < dist[v]) {
            return true;  // Negative cycle
        }
    }
    return false;
}
// NOTEBOOK