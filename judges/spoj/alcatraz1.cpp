// ALCATRAZ1 - SUM OF DIGITS
// https://www.spoj.com/problems/ALCATRAZ1/

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    string number;

    while(n--) {
        cin >> number;
        long long sum = 0;

        for (char c : number) {
            sum += (long long)(c - '0');
        }

        cout << sum << endl;
    }
    return 0;
}
