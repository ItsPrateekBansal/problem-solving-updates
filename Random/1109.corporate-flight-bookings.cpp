/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> difference(n+1,0);
        for(auto b : bookings) {
            int l = b[0]-1;
            int r = b[1]-1;
            int v = b[2];
            difference[l] += v;
            difference[r+1] -= v;
        }
        vector<int> ans(n, 0);
        for(int i = 0 ; i < n ; i++) {
            int left = (i==0) ? 0 : ans[i-1];
            ans[i] = difference[i] + left;
        }
        return ans;
    }
};
// @lc code=end

