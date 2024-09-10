// Logical Sequence 2
// https://www.beecrowd.com.br/judge/en/problems/view/1145
// 28911345		1145	Logical Sequence 2	Accepted	C++17	0.051	7/18/22, 5:09:05 PM

#include <iostream>

using namespace std;

int main() {
    int x, y; cin >> x >> y;

    for (int i = 1; i <= y; i++) {
        cout << i;
        if (i % x > 0)
            cout << " ";
        if (i % x == 0)
            cout << endl;
    }

    return 0;
}
