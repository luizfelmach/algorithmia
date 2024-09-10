// A. Bit++
// https://codeforces.com/contest/282/problem/A
// 162672062	Jul/03/2022 15:19UTC-3	luizfelmach	A - Bit++	GNU C++14	Accepted	0 ms	0 KB

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define imax INT_MAX
#define imin INT_MIN
#define ING 0x3f3f3f3f
#define exp 1e9
#define sz(x) (int((x).size()))

int main() { _
    int n; cin >> n;
    cin.ignore();
    int res = 0;
    string op;
    while(n--) {
        getline(cin, op);
        char f = op[1];
        if(f == '+') res++;
        else res--;
    }
    cout << res << endl;
    return 0;
}
