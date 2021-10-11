/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, cur = values[0]-1;
        for(int i = 1; i < values.size(); i++,cur--) {
            ans = max(ans,cur+values[i]);
            if(cur < values[i]) cur = values[i];
        }
        return ans;
    }
};
// @lc code=end

