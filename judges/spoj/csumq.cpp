// CSUMQ - Cumulative Sum Query
// https://www.spoj.com/problems/CSUMQ/

#include <iostream>
using namespace std;

int sum(int vet[], int a, int b) {
	int sum  = 0;
	for (int i = a; i <= b; i++) {
		sum += vet[i];
	}
	return sum;
}

int main() {
	int n, q;
	cin >> n;
	int nums[n];

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	cin >> q;

	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		cout << sum(nums, a, b) << endl;
	}
	return 0;
}
