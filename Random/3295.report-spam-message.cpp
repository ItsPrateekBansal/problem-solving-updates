/*
 * @lc app=leetcode id=3295 lang=cpp
 *
 * [3295] Report Spam Message
 */

// @lc code=start
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> checker;
        for(auto ban : bannedWords) checker.insert(ban);
        int x = 0;
        for(auto m : message) {
            if(checker.find(m) != checker.end()) x++;
            if(x == 2) return true;
        }
        return false;
    }
};
// @lc code=end

