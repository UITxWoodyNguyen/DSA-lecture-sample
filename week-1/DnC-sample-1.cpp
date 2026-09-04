#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(const int arr[], int n, int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) return mid;
        if (arr[mid] > value) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int recBinarySearch(const int arr[], int value, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (arr[mid] == value) return mid;
    if (arr[mid] > value) return recBinarySearch(arr, value, left, mid - 1);
    return recBinarySearch(arr, value, mid + 1, right);
}

int main() {
    int n;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int value;
    cin >> value;
    int result = binarySearch(arr, n, value);
    cout << result << endl;

    result = recBinarySearch(arr, value, 0, n - 1);
    cout << result << endl;
}