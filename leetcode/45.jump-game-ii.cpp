/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int to = 0, mx = 0, ans = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums.size()-1 <= to) return ans;
            mx = max(mx,i+nums[i]);
            if(i == to) {
                to = mx;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

