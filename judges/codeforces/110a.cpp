// A. Nearly Lucky Number
// https://codeforces.com/contest/110/problem/A
// 161247462	Jun/19/2022 14:41UTC-3	luizfelmach	A - Nearly Lucky Number	GNU C++14	Accepted	30 ms	0 KB

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
    unsigned ll n; cin >> n;
    int count = 0;
    while(n != 0) {
        unsigned ll dig = n % 10;
        if (dig == 4 || dig == 7) {
            count++;
        }
        n /= 10;
    }
    if (count == 4 || count == 7) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
