#include <bits/stdc++.h>

using namespace std;

int roberto[] = {2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987};
int t_roberto = 14;

int main() {
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;

        int flag = 0;
        for (int i = 0; i < t_roberto; i++) {
            if (roberto[i] == n) {
                cout << "Roberto\n";
                flag = 1;
                break;
            }
        }
        if (!flag) cout << "Alicia\n";
    }

    return 0;
}
