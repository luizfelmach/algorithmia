#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

// NOTEBOOK
// KMP algorithm to find all occurrences of a pattern in a string
// Time complexity: O(n + m), where n is the length of the text and m is the
// length of the pattern

// T is text
// P is pattern
// B is back table

vi kmp_preprocess(string P) {
    int m = P.size();
    int i = 0, j = -1;
    vi  back(m + 10);
    back[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j = back[j];
        i++;
        j++;
        back[i] = j;
    }
    return back;
}

void kmp(string T, string P) {
    vi  back = kmp_preprocess(P);
    int n    = T.size();
    int m    = P.size();
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) j = back[j];
        i++;
        j++;
        if (j == m) {
            printf("P is found at index %d in T\n", i - j);
            j = back[j];
        }
    }
}

int main() {
    string TEXT    = "I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN";
    string PATTERN = "SEVENTY SEV";
    kmp(TEXT, PATTERN);
    return 0;
}
// NOTEBOOK