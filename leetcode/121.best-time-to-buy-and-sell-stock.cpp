/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, mx = 0;
        for(int &x : prices) {
            if(x < mn) mn = x;
            else if(x - mn > mx) mx = x - mn;
        }
        return mx;
    }
};
// @lc code=end

