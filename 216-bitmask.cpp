#include <bits/stdc++.h>

#include <cmath>

using namespace std;

const int INF = 0x3f3f3f3f;

int n;
int x[20];
int y[20];
float dp[20][10000];
int visited[20][100000];

float dist(int p1, int p2) {
    int x1 = x[p1];
    int y1 = y[p1];
    int x2 = x[p2];
    int y2 = y[p2];
    float sum = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return sqrt(sum);
}

float solve(int last, int bitmask) {
    if (bitmask == ((1 << n) - 1)) {
        return 0;
    }

    float result = INF;
    float &ans = dp[last][bitmask];
    if (visited[last][bitmask] != -1) return ans;

    for (int i = 0; i < n; i++) {
        if (!(bitmask & 1 << i)) {
            result =
                min(result, 16 + dist(last, i) + solve(i, bitmask | 1 << i));
        }
    }

    return ans = result;
}

void recover(int last, int bitmask) {
    if (bitmask == ((1 << n) - 1)) {
        return;
    }
    cout << "Cable requirement to connect ";
    cout << "(" << x[last] << "," << y[last] << ")";

    int pos = 0;
    float mindist = INF;
    for (int i = 0; i < n; i++) {
        if (!(bitmask & 1 << i)) {
            float result = 16 + dist(last, i) + solve(i, bitmask | 1 << i);
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

    recover(pos, bitmask | 1 << pos);
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

        int pos = 0;
        float mindist = 123123123.0;

        for (int i = 0; i < n; i++) {
            // cout << i << endl;
            memset(visited, -1, sizeof(visited));
            float result = solve(i, 1 << i);
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
        memset(visited, -1, sizeof(visited));

        // cout << "POSICAO MELHOR: " << pos << endl;
        // float result = solve(pos);
        recover(pos, 1 << pos);
        cout << setprecision(2) << fixed;
        cout << "Number of feet of cable required is " << mindist << "."
             << endl;
        count++;
    }

    return 0;
}
