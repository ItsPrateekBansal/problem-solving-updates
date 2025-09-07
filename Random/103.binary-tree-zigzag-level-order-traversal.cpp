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
        queue<pair<TreeNode*, int>> q, trav;
        q.push(make_pair(root, 0));
        trav.push(q.front());
        while(q.size()) {
            TreeNode* temp = q.front().first;
            int l = q.front().second + 1;
            q.pop();
            if(temp->left) {
                q.push(make_pair(temp->left, l));
                trav.push(make_pair(temp->left, l));
            }
            if(temp->right) {
                q.push(make_pair(temp->right, l));
                trav.push(make_pair(temp->right, l));
            } 
        }
        vector<vector<int>> ans;
        while(trav.size()) {
            int m = trav.front().second;
            vector<int> q;
            if(m%2==0) {
                while(trav.size() && trav.front().second == m) {
                    q.push_back(trav.front().first->val);
                    trav.pop();
                }
            } else {
                stack<int> st;
                while(trav.size() && trav.front().second == m) {
                    st.push(trav.front().first->val);
                    trav.pop();
                }
                while(st.size()) {
                    q.push_back(st.top());
                    st.pop();
                }
            }
            ans.push_back(q);
        }
        return ans;
    }
};
// @lc code=end

