// Vestibular
// https://neps.academy/br/exercise/160
// 570377 Vestibular C++ Accepted 100 10:16:51 20/07/2022

#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	string gabarito;
	string prova;

	cin >> gabarito;
	cin >> prova;

	int cont = 0;

	for (int i = 0; i < n; i++) {
		if (gabarito[i] == prova[i])
			cont++;
	}

	cout << cont << endl;

	return 0;
}
