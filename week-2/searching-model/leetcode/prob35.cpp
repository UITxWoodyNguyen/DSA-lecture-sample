#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        bool isFound = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                isFound = 1;
                return mid;
            }
            if (target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        }

        if (!isFound) {
            l = 0, r = nums.size() - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            }
        }

        return l;
    }
};