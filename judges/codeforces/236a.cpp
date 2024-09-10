// A. Boy or Girl
// https://codeforces.com/contest/236/problem/A
// 163146328	Jul/07/2022 17:23UTC-3	luizfelmach	A - Boy or Girl	GNU C++14	Accepted	30 ms	100 KB

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
    set<char> letters;
    char l;
    while(cin >> l) {
        letters.insert(l);
    }

    if (letters.size() % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;
    return 0;
}
