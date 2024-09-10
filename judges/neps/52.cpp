// Lâmpadas
// https://neps.academy/br/exercise/52
// 569731 Lâmpadas C++ Accepted 100 17:20:48 18/07/2022

#include <iostream>

using namespace std;

int main() {

    int a = 0, b = 0;

    int n; cin >> n;

    int itp;
    while(n--) {
        cin >> itp;

        if (itp == 1)
            a = !a;
        else {
            a = !a;
            b = !b;
        }
    }


    cout << a << endl;
    cout << b << endl;
    return 0;
}
