#include <iostream>
#include <algorithm>
using namespace std;

// Binary Search Algorithm - example of Divide and Conquer Algo
class Solution {
    private:
        int n;
        int arr[1000];

    public:
        int getSolutionSize() {
            return n;
        }

        void input() {
            cin >> n;
            for(int i = 0; i < n; i++) cin >> arr[i];
            sort(arr, arr + n); // Binary Search requires sorted array
        }

        // Original Binary Search
        int BinarySearch (int value) {
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (arr[mid] == value) return mid;
                if (arr[mid] > value) right = mid - 1;
                else left = mid + 1;
            }

            return -1;  // No Solution Found
        }
        
        // Binary Search using Recursion
        int RecBinarySearch (int value, int left, int right) {
            if (left > right) return -1;
            int mid = (left + right) / 2;
            if (arr[mid] == value) return mid;
            if (arr[mid] > value) return RecBinarySearch(value, left, mid - 1);
            else return RecBinarySearch(value, mid+1, right);
        }
};

int main () {
    Solution P;
    P.input();

    int value;
    cin >> value;
    int result = P.BinarySearch(value);
    cout << result << endl;

    result = P.RecBinarySearch(value, 0, P.getSolutionSize() - 1);
    cout << result << endl;
}