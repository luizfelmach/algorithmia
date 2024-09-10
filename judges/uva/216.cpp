#include <bits/stdc++.h>

#include <cmath>

using namespace std;

const int INF = 0x3f3f3f3f;

int n;
int x[10];
int y[10];
int vis[10];

float dist(int p1, int p2) {
    int x1 = x[p1];
    int y1 = y[p1];
    int x2 = x[p2];
    int y2 = y[p2];
    float sum = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return sqrt(sum);
}

float solve(int last) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        flag &= vis[i];
    }
    if (flag) return 0;

    float result = INF;

    vis[last] = 1;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            result = min(result, 16 + dist(last, i) + solve(i));
            vis[i] = 0;
        }
    }
    vis[last] = 0;

    return result;
}

void recover(int last) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        flag &= vis[i];
    }
    if (flag) return;
    cout << "Cable requirement to connect ";
    cout << "(" << x[last] << "," << y[last] << ")";

    int pos = 0;
    float mindist = INF;
    vis[last] = 1;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            float result = 16 + dist(last, i) + solve(i);
            vis[i] = 0;
            if (result == mindist) {
            }
            if (result < mindist) {
                pos = i;
                mindist = result;
            }
        }
    }

    cout << " to (" << x[pos] << "," << y[pos] << ")";
    cout << " is " << setprecision(2) << fixed << 16 + dist(last, pos)
         << " feet." << endl;

    vis[pos] = 1;
    recover(pos);
    vis[pos] = 0;

    vis[last] = 0;
}

int main() {
    int count = 1;
    while (1) {
        cin >> n;
        if (n == 0) break;
        cout << "**********************************************************"
             << endl;
        cout << "Network #" << count << endl;
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

        memset(vis, 0, sizeof(vis));
        int pos = 0;
        float mindist = 123123123.0;

        for (int i = 0; i < n; i++) {
            // cout << i << endl;
            memset(vis, 0, sizeof(vis));
            float result = solve(i);
            // recover(i);
            // cout << result << endl;
            // if (abs(result - mindist) < 1e9) continue;
            if (result < mindist) {
                pos = i;
                mindist = result;
            }
        }

        // cout << "Escolhido: " << pos << endl;
        // continue;
        //

        // cout << "POSICAO MELHOR: " << pos << endl;
        memset(vis, 0, sizeof(vis));
        // float result = solve(pos);
        recover(pos);
        cout << setprecision(2) << fixed;
        cout << "Number of feet of cable required is " << mindist << "."
             << endl;
        count++;
    }

    return 0;
}
