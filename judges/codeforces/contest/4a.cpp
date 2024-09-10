// A. Watermelon
// https://codeforces.com/contest/4/problem/A
// 165013074	Jul/20/2022 10:09UTC-3	luizfelmach	A - Watermelon	GNU C++14	Accepted	30 ms	0 KB

#include <iostream>
using namespace std;

bool isEven(int n) {
	return n % 2 == 0;
}

int main() {
	int n; cin >> n;

	int k = n - 2;

	if (n == 2) k++;

	cout << (isEven(k) ? "YES" : "NO") << endl;

	return 0;
}
