#include <iostream>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f

int         n, t;
int         tracks[30];
vector<int> resp;

int solve(int cur, int soma) {
    if (cur == t) {
        if (soma <= n)
            return soma;
        else
            return -INF;
    }

    int pega  = solve(cur + 1, soma + tracks[cur]);
    int passa = solve(cur + 1, soma);

    return max(pega, passa);
}

void recover(int cur, int soma) {
    if (cur == t) return;
    int pega  = solve(cur + 1, soma + tracks[cur]);
    int passa = solve(cur + 1, soma);

    if (pega > passa) {
        cout << tracks[cur] << " ";
        recover(cur + 1, soma + tracks[cur]);
    } else {
        recover(cur + 1, soma);
    }
}

int main() {
    while (cin >> n >> t) {
        for (int i = 0; i < t; i++) cin >> tracks[i];

        recover(0, 0);
        cout << "sum:";
        cout << solve(0, 0) << endl;
    }
    return 0;
}
