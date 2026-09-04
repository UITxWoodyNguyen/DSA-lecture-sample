#include <iostream>
using namespace std;

// Linear Search Using FOR loops
int LinearSearchV1 (int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }

    return -1;
}

// Linear Search Using WHILE loops
int LinearSearchV2 (int arr[], int size, int target) {
    int i = 0;
    while (i < size) {
        if (arr[i] == target) return i;
        i++;
    }

    return -1;
}

// Linear Search Upgrade
int LinearSearchV3 (int arr[], int size, int target) {
    int i = 0;
    arr[size] = target;
    while (arr[i] != target) i++;

    if (i == size) return -1;
    return i;
}

int main () {
    int arr[] = {33, 1, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Linear Search using For Loops: " << LinearSearchV1(arr, size, target) << endl;
    cout << "Linear Search using While Loops: " << LinearSearchV2(arr, size, target) << endl;
    cout << "Linear Search Upgrade: " << LinearSearchV3(arr, size, target) << endl;
    return 0;
}