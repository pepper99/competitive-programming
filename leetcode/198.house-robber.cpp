/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            int k = max(nums[i-1], nums[i] + nums[i-2]);
            for(int j = i-2; j >= 0; j--) k = max(k, nums[i] + nums[j]);
            nums[i] = k;
        }
        return nums[nums.size()-1];
    }
};
// @lc code=end

