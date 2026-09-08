#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool isFirst) {
        int l = 0, r = nums.size() - 1;
        int res = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                res = mid;
                if (isFirst) r = mid - 1;
                else l = mid + 1;
            } else if (target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer;
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        answer.push_back(left);
        answer.push_back(right);
        return answer;
    }
};

int main () {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution sol;
    vector<int> result = sol.searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]";
}