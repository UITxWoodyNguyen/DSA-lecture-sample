#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void InsertionSort(int arr[], int n) {
    int i = 1;
    while (i < n) {
        int key = arr[i];
        int nearest = i - 1;
        while (nearest >= 0 && arr[nearest] > key) {
            arr[nearest + 1] = arr[nearest];
            nearest--;
        }

        arr[nearest + 1] = key;
        i++;
    }
}

void InsertionSortFor(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int nearest;
        for(nearest = i-1; nearest >= 0; nearest--) {
            if (arr[nearest] < key) break;
            arr[nearest + 1] = arr[nearest];
        }
        arr[nearest + 1] = key;
    }
}

void InsertionSortRecursive(int arr[], int n) {
    if (n < 2) return;  // Simplest case: size = 1 --> already sorted
    InsertionSortRecursive(arr, n - 1); // Sort first n-1 elements

    int key = arr[n-1];
    int nearest = n - 2;
    while (nearest >= 0 && arr[nearest] > key) {
        arr[nearest + 1] = arr[nearest];
        nearest--;
    }
    arr[nearest + 1] = key;
}

void BinaryInsertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int lo = 0, hi = i - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (arr[mid] > key) hi = mid - 1;
            else lo = mid + 1;
        }

        for(int j = i - 1; j >= lo; j--) arr[j+1] = arr[j];
        arr[lo] = key;
    }
}

int binarySearchRec(int arr[], int key, int left, int right) {
    if (left > right) return left;
    int mid = left + (right - left) / 2;
    if (arr[mid] <= key) return binarySearchRec(arr, key, mid + 1, right);
    return binarySearchRec(arr, key, left, mid - 1);
}

void BinaryInsertionSortRecursive(int arr[], int n) {
    if (n <= 1) return;
    BinaryInsertionSortRecursive(arr, n - 1);
    
    int key = arr[n - 1];
    int pos = binarySearchRec(arr, key, 0, n - 2);
    
    for (int j = n - 1; j > pos; j--) {
        arr[j] = arr[j - 1];
    }
    arr[pos] = key;
}

int main () {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    InsertionSort(arr, n);
    cout << "Sorted array (InsertionSort): ";
    printArray(arr, n);

    // Resetting the array for recursive sort
    int arr2[] = {12, 11, 13, 5, 6};
    InsertionSortRecursive(arr2, n);
    cout << "Sorted array (InsertionSortRecursive): ";
    printArray(arr2, n);

    // Resetting the array for for-loop sort
    int arr3[] = {12, 11, 13, 5, 6};
    InsertionSortFor(arr3, n);
    cout << "Sorted array (InsertionSortFor): ";
    printArray(arr3, n);

    // Resetting the array for binary insertion sort
    int arr4[] = {12, 11, 13, 5, 6};
    BinaryInsertionSort(arr4, n);
    cout << "Sorted array (BinaryInsertionSort): ";
    printArray(arr4, n);

    // Resetting the array for binary insertion sort recursive
    int arr5[] = {12, 11, 13, 5, 6};
    BinaryInsertionSortRecursive(arr5, n);
    cout << "Sorted array (BinaryInsertionSortRecursive): ";
    printArray(arr5, n);

    return 0;
}