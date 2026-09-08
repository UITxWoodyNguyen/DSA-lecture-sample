#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid = 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        while (nums[mid] != maxVal) mid++;

        if (target == nums[mid]) return mid;

        int l = 0, r = mid - 1;
        bool isFound = 0;
        while (l <= r) {
            int mid_ = (l + r) >> 1;
            if (nums[mid_] == target) {
                isFound = 1;
                return mid_;
            }

            if (target < nums[mid_]) r = mid_ - 1;
            else l = mid_ + 1;
        }

        if (!isFound) {
            l = mid + 1, r = nums.size() - 1;
            while (l <= r) {
                int mid_ = (l + r) >> 1;
                if (nums[mid_] == target) {
                    isFound = 1;
                    return mid_;
                }

                if (target < nums[mid_]) r = mid_ - 1;
                else l = mid_ + 1;
            }
        }

        return -1;
    }
};