// Ordenação Simples
// https://neps.academy/br/exercise/176
// 572116 Ordenação Simples C++ Accepted 100 19:01:11 23/07/2022

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n -1; j++) {
            int atual = nums[j];
            int prox = nums[j+1];
            if (atual > prox) {
                nums[j] = prox;
                nums[j+1] = atual;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
