/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return root != nullptr && hasPathSum(root, 0, targetSum);
    }

    bool hasPathSum(TreeNode* root, int current, int &targetSum) {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr) return current + root->val == targetSum;
        return hasPathSum(root->left, current + root->val, targetSum) ||
                hasPathSum(root->right, current + root->val, targetSum);
    }
};
// @lc code=end

