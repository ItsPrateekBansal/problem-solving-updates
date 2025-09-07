/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(i>maxReach) return false;
            maxReach = max(maxReach, i+nums[i]);
        }
        return maxReach>=nums.size()-1;
    }
};
// @lc code=end

