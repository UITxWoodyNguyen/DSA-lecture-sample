#include <iostream>
using namespace std;

// Linear Search Algorithm - example of Brute Force Algo
class Solution {
    private:
        int n;
        int arr[1000];

    public:
        void input() {
            cin >> n;
            for(int i = 0; i < n; i++) cin >> arr[i];
        }

        int LinearSearch (int value) {
            for(int i = 0; i < n; i++) if (arr[i] == value) return i+1;
            return -1;
        }
};

int main() {
    Solution P;
    P.input();

    int value;
    cin >> value;
    int result = P.LinearSearch(value);
    cout << result << endl;
}