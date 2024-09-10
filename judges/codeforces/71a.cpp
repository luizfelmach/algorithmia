// A. Way Too Long Words
// https://codeforces.com/contest/71/problem/A
// 161341258	Jun/20/2022 17:07UTC-3	luizfelmach	A - Way Too Long Words	GNU C++14	Accepted	15 ms	100 KB

#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL);
 
int main() { _
    int n; cin >> n;
    cin.ignore();
    while(n--) {
        string line;
        getline(cin, line);
        int size = line.size();
        if (size > 10) {
            cout << line[0] << size - 2 << line[size -1] << endl;
        } else
            cout << line << endl;
    }
    return 0;
}
