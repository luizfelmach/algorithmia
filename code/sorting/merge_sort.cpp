#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

// NOTEBOOK
// Merge Sort
// The provided implementation enhances this basic approach by counting the
// number of inversions in the array.
// Time complexity: O(nlogn)
// Space complexity: O(n)

int merge(vi arr, vi aux, int lo, int hi, int mid) {
    int inv = 0;
    for (int k = lo; k <= hi; k++) aux[k] = arr[k];
    int i = lo;
    int j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid)
            arr[k] = aux[j++];
        else if (j > hi)
            arr[k] = aux[i++];
        else if (aux[j] < aux[i]) {
            arr[k] = aux[j++];
            inv += mid + 1 - i;
        } else
            arr[k] = aux[i++];
    }
    return inv;
}

int merge_sort(vi arr, vi aux, int lo, int hi) {
    int inv = 0;
    if (lo >= hi) return inv;
    int mid = lo + (hi - lo) / 2;
    inv += merge_sort(arr, aux, lo, mid);
    inv += merge_sort(arr, aux, mid + 1, hi);
    inv += merge(arr, aux, lo, hi, mid);
    return inv;
}
// NOTEBOOK

int main() {
    vi arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vi aux(arr);

    int inv = merge_sort(arr, aux, 0, arr.size() - 1);
    cout << inv << endl;

    return 0;
}