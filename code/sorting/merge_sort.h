// Merge sort with inversion counter

int merge(int *arr, int *aux, int lo, int hi, int mid) {
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

int mergesort(int *arr, int *aux, int lo, int hi) {
    int inv = 0;
    if (lo >= hi) return inv;
    int mid = lo + (hi - lo) / 2;
    inv += mergesort(arr, aux, lo, mid);
    inv += mergesort(arr, aux, mid + 1, hi);
    inv += merge(arr, aux, lo, hi, mid);
    return inv;
}
