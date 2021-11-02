/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        rec(root,ans);
        return ans;
    }
    
    int rec(TreeNode* crawl, int &ans) {
        int a = 0, b = 0;
        if(crawl->left) a = max(a,rec(crawl->left,ans));
        if(crawl->right) b = max(b,rec(crawl->right,ans));
        ans = max(ans, a + b + crawl->val);
        return max(a,b) + crawl->val;
    }
};
// @lc code=end

