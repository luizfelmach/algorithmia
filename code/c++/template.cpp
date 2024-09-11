#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define pf push_front
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define mset(x, y) memset(x, (y), sizeof(x));

typedef long long            ll;
typedef unsigned long long   ull;
typedef long double          ld;
typedef pair<int, int>       pii;
typedef pair<ll, ll>         pll;
typedef tuple<int, int, int> iii;
typedef vector<int>          vi;
typedef vector<pii>          vii;
typedef vector<ll>           vll;
typedef vector<ld>           vd;

const int INF   = 0x3f3f3f3f;
const ull INFLL = 0x3f3f3f3f3f3f3f3f;
const int MAX   = 1e5 + 200;
const ld  PI    = acos(-1);
const ld  EPS   = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

ostream& operator<<(ostream& os, const pii& pa) {
    return os << "(" << pa.fi << ", " << pa.se << ")";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(20) << fixed;

    return 0;
}