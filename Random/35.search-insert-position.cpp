/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int li = 0, hi = nums.size() - 1, mid, x;
        while(li <= hi) {
            mid = li + (hi-li)/2;
            x = nums[mid];
            if(x == target) return mid;
            if(x < target) li = mid + 1;
            else if(x > target) hi = mid - 1;
        }
        if(nums[mid] == target) return mid;
        if(nums[mid] > target) return mid;
        if(nums[mid] < target) return mid + 1;
        return 0;
    }
};
// @lc code=end

