// A. Wrong Subtraction
// https://codeforces.com/contest/977/problem/A
// 165008261	Jul/20/2022 09:25UTC-3	luizfelmach	A - Wrong Subtraction	GNU C++14	Accepted	0 ms	0 KB

#include <iostream>
using namespace std;

int main() {
	int n, k; cin >> n >> k;

	while(k--) {
		int last = n % 10;

		if (last == 0) {
			n /= 10;
		} else {
			n -= 1;
		}
	}

	cout << n << endl;
	return 0;
}
