// Fibonacci, How Many Calls?
// https://www.beecrowd.com.br/judge/en/problems/view/1029
// 28537936		1029	Fibonacci, How Many Calls?	Accepted	C++17	0.000	6/16/22, 7:43:16 PM

#include <bits/stdc++.h>
using namespace std;

int memo[50];
int calls[50];

int cal(int x) {
    if (calls[x] != -1) {
        return calls[x];
    }
    return calls[x] = 1 + cal(max(0, x - 1)) + cal(max(0, x - 2));
}

int fibo(int x) {
    if (memo[x] != -1) {
        return memo[x];
    }
    return memo[x] = fibo(max(0, x - 1)) + fibo(max(0, x - 2));
}

int main() {
    int qtd;
    cin >> qtd;
    while (qtd--) {
        int f;
        cin >> f;
        memset(memo, -1, sizeof memo);
        memset(calls, -1, sizeof calls);
        memo[0] = 0;
        memo[1] = 1;
        calls[0] = 1;
        calls[1] = 1;
        cout << "fib(" << f << ")" << " = " << cal(f) - 1 << " calls = " << fibo(f);
        cout << endl;
    }
    return 0;
}
