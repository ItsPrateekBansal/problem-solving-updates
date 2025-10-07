/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int low = 1, high = x;
        unsigned long long mid, val;
        unsigned long long ans = 0;
        while(low <= high) {
            mid = low + (high - low)/2;
            val = mid*mid;
            if(val == x) return mid;
            if(val > x) high = mid-1;
            else {
                low = mid+1;
                ans = max(ans, mid);
            }
        }
        return ans;
    }
};
// @lc code=end

