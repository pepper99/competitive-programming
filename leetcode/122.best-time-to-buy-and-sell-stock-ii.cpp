/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = 0, money = 0, bought = 0;
        if(prices.size() < 2) return 0;
        for(int i = 0; i < prices.size() - 1; i++) {
            if(bought == 1 && prices[i] > prices[i+1]) {
                money += prices[i] - hold;
                hold = 0;
                bought = 0;
            }
            else if(bought == 0 && prices[i] <= prices[i+1]) {
                hold = prices[i];
                bought = 1;
            }
        }
        if(bought) {
            money += prices[prices.size() - 1] - hold;
        }
        return money;
    }
};
// @lc code=end

