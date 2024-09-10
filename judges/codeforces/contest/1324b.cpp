// B. Yet Another Palindrome Problem
// https://codeforces.com/contest/1324/problem/B
// 165239101	Jul/21/2022 18:00UTC-3	luizfelmach	B - Yet Another Palindrome Problem	GNU C++14	Accepted	31 ms	100 KB

#include <iostream>
#include <vector>
using namespace std;

bool hasNumber(vector<int> vec, int n, int x) {

    for (int i = n; i < vec.size(); i++)
        if (vec[i] == x) return true;
    return false;
}

bool hasPalindrome(vector<int> nums) {
    int i, j, k, n = nums.size();
    vector<int> res;
    for (i = 0; i < n - 2; i++) {
        if (hasNumber(nums, i+2, nums[i]))
            return true;
    }
    return false;
}

int main() {

    int qtd; cin >> qtd;

    while(qtd--) {
        int n; cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
            cin >> nums[i];

        cout << (hasPalindrome(nums) ? "YES" : "NO") << endl;
    }
    return 0;
}

