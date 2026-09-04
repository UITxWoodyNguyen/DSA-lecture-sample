#include <iostream>
using namespace std;

int BinarySearch (int arr[], int size, int target) {
    int lo = 0, hi = size - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }

    return -1;
}

int RecursionBinarySearch (int arr[], int lo, int hi, int target) {
    if (lo > hi) return -1;

    int mid = (lo + hi) >> 1;
    if (arr[mid] == target) return mid;

    if (arr[mid] < target) return RecursionBinarySearch(arr, mid + 1, hi, target);
    else return RecursionBinarySearch(arr, lo, mid - 1, target);
}

int main () {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Binary Search: " << BinarySearch(arr, size, target) << endl;
    cout << "Recursion Binary Search: " << RecursionBinarySearch(arr, 0, size - 1, target) << endl;
    return 0;
}