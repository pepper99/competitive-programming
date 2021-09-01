/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), mx = 0;
        vector<vector<int>> dp(n);
        for(int i = n - 1; i >= 0; i--) {
            dp[i].resize(m);
            for(int j = m - 1; j >= 0; j--) {
                if(nums1[i] == nums2[j])
                    dp[i][j] = (i + 1 < n && j + 1 < m ? dp[i+1][j+1] : 0) + 1;
                mx = max(dp[i][j], mx);
            }
        }
        return mx;
    }
};
// @lc code=end

