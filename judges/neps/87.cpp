// Flíper
// https://neps.academy/br/exercise/87
// 569730 Flíper C++ Accepted 100 17:14:22 18/07/2022

#include <iostream>

using namespace std;

int main() {

    int p, r;
    cin >> p >> r;

    if (p == 0)
        cout << "C" << endl;
    else {
        if (r == 0)
            cout << "B" << endl;
        else
            cout << "A" << endl;
    }

    return 0;
}
