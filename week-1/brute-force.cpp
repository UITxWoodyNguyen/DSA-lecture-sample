#include <iostream>
using namespace std;

int linearSearch(const int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) return i + 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int value;
    cin >> value;
    int result = linearSearch(arr, n, value);
    cout << result << endl;
}