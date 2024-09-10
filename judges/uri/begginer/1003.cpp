// Simple Sum
// https://www.beecrowd.com.br/judge/en/problems/view/1003
// 28405733		1003	Simple Sum	Accepted	C++17	0.000	6/8/22, 6:51:25 PM

#include <iostream>

using namespace std;

int main() {
	int soma = 0;
	int n1, n2;
	cin >> n1 >> n2;
	soma += n1 + n2;
	cout << "SOMA = " << soma << endl;
	return 0;
}
