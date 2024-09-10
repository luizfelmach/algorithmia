// A. Anastasia and pebbles
// https://codeforces.com/contest/789/problem/A
// 165247365	Jul/21/2022 21:30UTC-3	luizfelmach	A - Anastasia and pebbles	GNU C++14	Accepted	374 ms	600 KB

#include <iostream>
#include <stack>
using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    stack<int> pedras;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        pedras.push(a);
    }

    int cont = 0;
    while(!pedras.empty()) {
        int top = pedras.top();
        pedras.pop();


        while(top > 0) {

            if (top <= k and !pedras.empty()) {
                top = pedras.top();
                pedras.pop();
                top -= k;
            } else {
                top -= 2* k;
            }

            cont++;
        }
    }

    cout << cont << endl;

    return 0;
}

