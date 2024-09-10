// Floyd-Warshall

// Pre compute Dij values
// dist[i][j] = 0 if i == j
// dist[i][j] = Dij if there is edge to (i, j)
// dist[i][j] = INF if there is no edge to (i, j)

int V;
int dist[VMAX][VMAX];

void floyd_warshall() {
    for (int k = 0; k < V; k++)
    for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
        if (dist[i][j] > dist[i][k] + dist[k][j])
            dist[i][j] = dist[i][k] + dist[k][j];
}
