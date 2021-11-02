/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int dp[height.size()];
        int mx = 0, ans = 0;
        for(int i = 0; i < height.size(); i++) {
            mx = max(mx,height[i]);
            dp[i] = max(mx - height[i],0);
        }
        mx = 0;
        for(int i = height.size() - 1; i >= 0; i--) {
            mx = max(mx,height[i]);
            ans += min(dp[i],max(mx - height[i],0));
        }
        return ans;
    }
};
// @lc code=end

