#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// Selection Sort with WHILE loops
void selectionSort(int arr[], int n) {
    int i = 0;
    while (i < n) {
        int minIdx = i, j = i + 1;
        while (j < n) {
            if (arr[j] < arr[minIdx]) minIdx = j;
            j++;
        }

        swap(arr[i], arr[minIdx]);
        i++;
    }
}

// Selection Sort with FOR loops
void selectionSortFor(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main () {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);
    cout << "Sorted array using WHILE loops: ";
    printArray(arr, n);

    // Resetting the array for the next sort
    int arr2[] = {64, 25, 12, 22, 11};
    selectionSortFor(arr2, n);
    cout << "Sorted array using FOR loops: ";
    printArray(arr2, n);

    return 0;
}