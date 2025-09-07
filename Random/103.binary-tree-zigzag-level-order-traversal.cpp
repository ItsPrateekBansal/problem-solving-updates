/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> zigZagOrderArray;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int order = 1;
        while(nodes.size()) {
            int visitCount = nodes.size();
            vector<int> level(visitCount);
            for(int i = 0 ; i < visitCount ; i++) {
                TreeNode* temp = nodes.front();
                if(temp->left) nodes.push(temp->left);
                if(temp->right) nodes.push(temp->right);
                nodes.pop();
                if(order==0) {
                    level[visitCount - i - 1] = temp->val;
                } else {
                    level[i] = temp->val;
                }
            }
            zigZagOrderArray.push_back(level);
            order = (order == 0) ? 1 : 0;
        }
        return zigZagOrderArray;
    }
};
// @lc code=end

