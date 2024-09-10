#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int n;
vector<int> h;
vector<int> w;
int dp1[100000];
int dp2[100000];

int lis(int pos) {
    if (pos == 0) return w[pos];

    int &ans = dp1[pos];
    if (ans != -1) return ans;

    int result = w[pos];

    for (int i = 0; i < pos; i++) {
        if (h[i] < h[pos]) {
            result = max(result, w[pos] + lis(i));
        }
    }

    return ans = result;
}

int lds(int pos) {
    if (pos == 0) return w[pos];

    int &ans = dp2[pos];
    if (ans != -1) return ans;

    int result = w[pos];

    for (int i = 0; i < pos; i++) {
        if (h[i] > h[pos]) {
            result = max(result, w[pos] + lds(i));
        }
    }

    return ans = result;
}

int main() {
    int count = 1;
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        int tmp;
        h.clear();
        w.clear();

        for (int i = 0; i < n; i++) {
            cin >> tmp;
            h.push_back(tmp);
        }
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            w.push_back(tmp);
        }

        int linc = -INF;
        int ldec = -INF;
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));

        cout << "Case " << count << ". ";
        for (int i = 0; i < n; i++) {
            linc = max(linc, lis(i));
            ldec = max(ldec, lds(i));
        }

        if (linc >= ldec) {
            cout << "Increasing (" << linc << "). Decreasing (" << ldec
                 << ").\n";
        } else {
            cout << "Decreasing (" << ldec << "). Increasing (" << linc
                 << ").\n";
        }
        count++;
    }

    return 0;
}
