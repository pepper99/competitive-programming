/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 0) return 0;
        int dp[prices.size()][2];
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][1] - prices[i], dp[i-1][0]);
            dp[i][1] = max(prices[i] + dp[i-1][0] - fee, dp[i-1][1]);
        }
        return dp[prices.size()-1][1];
    }
};
// @lc code=end

