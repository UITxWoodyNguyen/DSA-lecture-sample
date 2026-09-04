#include <iostream>
using namespace std;

int InterpolationSearch (int arr[], int size, int target) {
    int lo = 0, hi = size - 1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) * (target - arr[lo])) / (arr[hi] - arr[lo]);
        if (arr[mid] == target) return mid;

        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }

    return -1;
}

int RecursionInterpolationSearch (int arr[], int lo, int hi, int target) {
    if (lo > hi) return -1;

    int mid = lo + ((hi - lo) * (target - arr[lo])) / (arr[hi] - arr[lo]);
    if (arr[mid] == target) return mid;

    if (arr[mid] < target) return RecursionInterpolationSearch(arr, mid + 1, hi, target);
    else return RecursionInterpolationSearch(arr, lo, mid - 1, target);
}

int main () {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Interpolation Search: " << InterpolationSearch(arr, size, target) << endl;
    cout << "Recursion Interpolation Search: " << RecursionInterpolationSearch(arr, 0, size - 1, target) << endl;
    return 0;
}