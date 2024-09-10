// Fibonacci
// https://neps.academy/br/exercise/257
// 570364 Fibonacci C++ Accepted 100 09:39:08 20/07/2022

#include <iostream>
using namespace std;

int fibo(int n) {
	if (n <= 1)
		return 1;
	return fibo(n - 1) + fibo(n - 2);
}

int main() {
	int k; cin >> k;

	cout << fibo(k) << endl;
	return 0;
}
