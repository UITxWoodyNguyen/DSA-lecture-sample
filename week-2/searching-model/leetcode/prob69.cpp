#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (mid * mid == x) return mid;
            if (mid * mid > x) r = mid - 1;
            else l = mid + 1;
        }

        return l - 1;
    }
};