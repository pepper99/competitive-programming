/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    void dfs(TreeNode* root, int targetSum, vector<int> &path, int sum, vector<vector<int>> &sol) {
        sum += root->val;
        path.push_back(root->val);
        if(root->left == nullptr & root->right == nullptr) {
            if(sum == targetSum) sol.push_back(path);
        }
        if(root->left != nullptr) dfs(root->left, targetSum, path, sum, sol);
        if(root->right != nullptr) dfs(root->right, targetSum, path, sum, sol);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> sol;
        if(root != nullptr) dfs(root, targetSum, path, 0, sol);
        return sol;
    }
};
// @lc code=end

