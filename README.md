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
  - Se T e L forem iguais, pare o laço. (`i` será o tamanho do ciclo.)

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

    cout << "Upper Bound" << endl;
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
