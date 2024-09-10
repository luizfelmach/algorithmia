// Huaauhahhuahau
// https://neps.academy/br/exercise/118
// 571636 Huaauhahhuahau C++ Accepted 100 19:49:24 22/07/2022

#include <iostream>
using namespace std;

bool ehVogal(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

bool ehPalindromo(string s) {

    for (int i = 0, j = s.size() -1; i < s.size()/2; i++, j--) {
        if (s[i] != s[j]) return false;
    }

    return true;
}

int main() {
    string risada;
    char l;
    while(cin >> l) {
        if (ehVogal(l))
            risada.append(1, l);
    }

    cout << (ehPalindromo(risada) ? "S" : "N") << endl;
    return 0;
}
