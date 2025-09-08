/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool validateBST(TreeNode* root, long long mini, long long maxi) {
        if(!root) return true;
        if(root->val <= mini || root->val >= maxi) return false;
        if(!root->left && !root->right) {
            if(root->val > mini && root->val < maxi) return true;
        }
        return validateBST(root->left, mini, root->val) 
            && validateBST(root->right, root->val, maxi);
    }
    bool isValidBST(TreeNode* root) {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end

