/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        
        int dp[prices.size()][2];
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            if(i-2 < 0) dp[i][0] = max(dp[i-1][0], -prices[i]);
            else dp[i][0] = max(dp[i-1][0], dp[i-2][1]-prices[i]);
            
            dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0]);
            cout << dp[i][0] << ' ' << dp[i][1] << '\n';
        }
        return dp[prices.size()-1][1];
    }
};
// @lc code=end

