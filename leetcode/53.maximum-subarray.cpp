/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0], sf = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            sf = max(sf + nums[i], nums[i]);
            mx = max(sf, mx);
        }
        return mx;
    }
};
// @lc code=end

