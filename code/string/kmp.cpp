#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

// NOTEBOOK
// KMP algorithm to find all occurrences of a pattern in a string
// Time complexity: O(n + m), where n is the length of the text and m is the
// length of the pattern

string T, P;     // T -> text P -> pattern
int    b[MAXN];  // b -> back table

void kmp_preprocess() {
    // Call this before calling kmp()
    int n = T.size();
    int m = P.size();
    int i = 0, j = -1;
    b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++;
        j++;
        b[i] = j;
    }
}

void kmp() {
    int n = T.size();
    int m = P.size();
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) j = b[j];
        i++;
        j++;
        if (j == m) {
            printf("P is found at index %d in T\n", i - j);
            j = b[j];
        }
    }
}
// NOTEBOOK

int main() {
    T = "I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN";
    P = "SEVENTY SEVEN";
    kmp_preprocess();
    kmp();
    return 0;
}