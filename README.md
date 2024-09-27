# Algorithms

### Complexity

|    n    |  Worst AC algorithm   | e.g.                              |
| :-----: | :-------------------: | :-------------------------------- |
|  <= 10  |     O(n!), O(n⁶)      | Permutation                       |
|  <= 20  |     O(2ⁿ), O(n⁵)      | DP + Bitmask                      |
|  <= 50  |         O(n⁴)         | DP with 3d + O(n) loop            |
| <= 100  |         O(n³)         | Floyd Warshall's                  |
|  <= 1K  |         O(n²)         | Bubble/Selection/Insertion Sort   |
| <= 100K |      O(nlog(n))       | Merge Sort, building Segment Tree |
|  <= 1M  | O(n), O(log(n)), O(1) | Binary search                     |

### Bitwise

|        Operação         |                            Descrição                            |
| :---------------------: | :-------------------------------------------------------------: |
|      x & (1 << k)       |                Verifica se o bit `k` está ativo.                |
|    x &#124; (1 << k)    |                     Seta o bit `k` como 1.                      |
|      x & ~(1 << k)      |                     Seta o bit `k` como 0.                      |
|      x ^ (1 << k)       |                       Inverte o bit `k`.                        |
|       x & (x - 1)       |           Seta o bit menos significativo de 1 para 0.           |
|         x & -x          |     Seta todos os bits exceto o menos significativo para 0.     |
|    x &#124; (x - 1)     |       Inverte todos os bits antes do menos significativo.       |
|    x & (x - 1) == 0     |          Verifica se um número é uma potência de dois.          |
|        1LL << k         |                      Shift para long long.                      |
|   \_\_builtin_clz(x)    |   Número de zeros à esquerda na representação binária de `x`.   |
|   \_\_builtin_ctz(x)    |   Número de zeros à direita na representação binária de `x`.    |
| \_\_builtin_popcount(x) |        Número de bits 1 na representação binária de `x`.        |
|  \_\_builtin_parity(x)  | Paridade do número de bits 1 em `x` (0 para par, 1 para ímpar). |

### Tortoise and Hare Algorithm (Cycle Detection)

- Comece com dois ponteiros apontando para o início da lista: T e L.
- Em um laço:
  - Incremente T em **uma** posição.
  - Incremente L em **duas** posições.
  - Se T e L forem iguais, pare o laço.
- Volte T para o início da lista e mantenha L onde estava.
- Em um laço:
  - Incremente T em **uma** posição.
  - Incremente L em **uma** posição.
  - Se T forem iguais, pare o laço e armazene a posição.
- Inicialize um contador `i` com o valor zero.
- Em um laço:
  - Incremente L em **uma** posição.
  - Incremente o valor de `i`.
  - Se T e L forem iguais, pare o laço. (`i` será o tamanho do ciclo.).

### D&C (Divide and Conquer)

```cpp
// Bisection Method
// Very useful for finding roots of a function

// F(x)
// ^     F(lo)
// |   *
// |   | *
// |   |  *
// |   |   *  Goal
// |--------O-------------------------> x
// |          *              |
// |            *            *
// |              *       *   F(hi)
// |                * * *

double bisection(double lo, double hi) {
    for (int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        double F = f(mid); // Declare a function
        if (F > 0) lo = mid;
        else hi = mid;
    }
    return lo;
}
```

```cpp
// Ternary search
// Very useful for finding max/min values between interval

// F(x)
// ^                 Goal
// |                o
// |             *     *
// |           *         *
// |         *             *
// |--------*----------------*-----------> x
// |   |   *                   *  |
// |   | *                        * F(r)
// |   * F(l)
// |

double ternary_search(double l, double r) {
    double eps = 1e-9;
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);
        double f2 = f(m2);
        if (f1 < f2) l = m1;
        else r = m2;
    }
    return f(l); // Return the maximum of f(x) in [l, r]
}
```

```cpp
//  - binary_search
//  - lower_bound
//  - upper_bound
//  - equal_range

int main() {
    vector<int> v = {10, 20, 30, 30, 20, 10, 10, 20};

    sort(begin(v), end(v));

    for (auto i : v) {
        cout << i << " ";  // 10 10 10 20 20 20 30 30
    }
    cout << endl;

    cout << binary_search(begin(v), end(v), 12) << endl;  // false
    cout << binary_search(begin(v), end(v), 30) << endl;  // true

    // Estamos buscando o primeiro elemento que seja >= x
    auto l1 = lower_bound(begin(v), end(v), 20);
    auto l2 = lower_bound(begin(v), end(v), 100);
    auto l3 = lower_bound(begin(v), end(v), 25);

    cout << "Found 20: " << (l1 != v.end()) << endl;            // true
    cout << "Found 100: " << (l2 != v.end()) << endl;           // false
    cout << "Found 25: " << (l3 != v.end()) << endl;            // true
    cout << "Where is 20: " << (l1 - v.begin()) << endl;        // 3
    cout << "Lower bound of 25: " << (l3 - v.begin()) << endl;  // 6

    // Estamos buscando o primeiro elemento que seja > x
    auto u1 = upper_bound(begin(v), end(v), 20);
    auto u2 = upper_bound(begin(v), end(v), 100);
    auto u3 = upper_bound(begin(v), end(v), 25);

        cout << "Found 20: " << (u1 != v.end()) << endl;            // true
    cout << "Found 100: " << (u2 != v.end()) << endl;           // false
    cout << "Found 25: " << (u3 != v.end()) << endl;            // true
    cout << "Where is 20: " << (u1 - v.begin()) << endl;        // 6
    cout << "Upper bound of 25: " << (u3 - v.begin()) << endl;  // 6

    cout << "Equal Range" << endl;
    auto eq = equal_range(begin(v), end(v), 20);
    cout << *eq.first << " " << *eq.second << endl;  // 20 30

    return 0;
}
```

### Sorting

```cpp
// Merge sort with inversion counter

int merge(int *arr, int *aux, int lo, int hi, int mid) {
    int inv = 0;
    for (int k = lo; k <= hi; k++) aux[k] = arr[k];
    int i = lo;
    int j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid) arr[k] = aux[j++];
        else if (j > hi) arr[k] = aux[i++];
        else if (aux[j] < aux[i]) {
            arr[k] = aux[j++];
            inv += mid + 1 - i;
        }
        else arr[k] = aux[i++];
    }
    return inv;
}

int mergesort(int *arr, int *aux, int lo, int hi) {
    int inv = 0;
    if (lo >= hi) return inv;
    int mid = lo + (hi -lo) / 2;
    inv += mergesort(arr, aux, lo, mid);
    inv += mergesort(arr, aux, mid + 1, hi);
    inv += merge(arr, aux, lo, hi, mid);
    return inv;
}
```

### Graph

```cpp
// Depth first search

int        V;
vector<vi> adj;
bool       vis[VMAX];
vi         topsort; // Topological Sort.
                    // Only works in directed acyclic graph.

void dfs(int s) {
    vis[s] = true;
    for (auto a : adj[s]) {
        if (!vis[a]) {
            dfs(a);
        }
    }
    topsort.push_back(s); // Only works in DAG.
}
```

```cpp
// Breadth first search

int        V;
vector<vi> adj;
bool       vis[VMAX];
int        dist[VMAX];
int        parent[VMAX];

void bfs(int s) {
    queue<int> f;  // Stack -> DFS
    f.push(s);
    vis[s] = true;
    parent[s] = -1;
    while (!f.empty()) {
        int v = f.front();
        f.pop();
        for (auto a : adj[v]) {
            if (!vis[a]) {
                vis[a] = true;
                dist[a] = dist[v] + 1;
                parent[a] = v;
                f.push(a);
            }
        }
    }
}
```

```cpp
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
```

```cpp
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
```

```cpp
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
```

```cpp
// Find articulations and bridges in an undirected graph
// Articulation is a vertex that, if removed, increases the number of connected components.
// Bridge is an edge that if removed the number of connected components increases.

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
```

```cpp
// Dijkstra

int         V;
vector<vii> adj;

vi dijkstra(int s) {
    vi dist(V, INF);
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        for (auto u : adj[v]) {
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

```

```cpp
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
```

```cpp
// Ford-Fulkerson Algorithm
// Min-Cut/Max-Flow problem

int        V;
vector<vi> adj;
vector<vi> capacity;

int bfs(int s, int t, vi& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty()) {
        int cur  = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vi  parent(V);
    int new_flow;
    while ((new_flow = bfs(s, t, parent))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}
```
