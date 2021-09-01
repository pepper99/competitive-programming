/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return rec(nums, 0, nums.size());
    }
    
    TreeNode* rec(vector<int>& nums, int l, int r) {
        if(r-l == 0) return nullptr;
        else if(r-l == 1) return new TreeNode(nums[l]);
        else if(r-l == 2) return new TreeNode(nums[l+1], new TreeNode(nums[l]), nullptr);
        int pos = (l+r) >> 1;
        return new TreeNode(nums[pos], rec(nums, l, pos), rec(nums, pos+1, r));
    }
};
// @lc code=end

