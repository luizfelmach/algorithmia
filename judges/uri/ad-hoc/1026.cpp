// To Carry or not to Carry
// https://www.beecrowd.com.br/judge/en/problems/view/1026
// 28450828		1026	To Carry or not to Carry	Accepted	C++17	0.309	6/11/22, 3:10:47 PM

#include <iostream>

using namespace std;

int main() {
    unsigned int a, b;
    while (cin >> a >> b) {
        cout << (a ^ b) << endl;
    }
    return 0;
}
