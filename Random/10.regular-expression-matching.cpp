/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool solve(int i, int j, string s, string p, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) return memo[i][j];
        bool ans;
        if(j==p.size()) {
            ans =  i == s.size();
        } else {
            bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
            if(j+1 < p.size() && p[j+1] == '*') {
                ans = memo[i][j] = solve(i, j+2, s, p,memo) || (match && solve(i+1, j, s, p,memo));
            } else if(match) {
                ans = memo[i][j] = solve(i+1, j+1, s, p,memo);
            } else {
                ans = false;
            }
        }
        memo[i][j] = ans;
        return memo[i][j];
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> memo;
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));

        return solve(0,0,s,p, memo);
    }
};
// @lc code=end

