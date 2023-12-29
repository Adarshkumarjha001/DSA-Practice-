#include <iostream>
using namespace std;

void selectionsort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minindex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        swap(arr[minindex], arr[i]);
    }
}

int main() {
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selectionsort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
