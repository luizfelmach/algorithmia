// A. Bear and Big Brother
// https://codeforces.com/contest/791/problem/A
// 165009396	Jul/20/2022 09:35UTC-3	luizfelmach	A - Bear and Big Brother	GNU C++14	Accepted	15 ms	0 KB

#include <iostream>
using namespace std;

int main() {
	int a, b; cin >> a >> b;

	int cont = 0;
	while(a <= b) {
		a *= 3;
		b *= 2;
		cont++;
	}

	cout << cont << endl;

	return 0;
}

