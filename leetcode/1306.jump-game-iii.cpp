/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vs(arr.size());
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            if(arr[x] == 0) return true;
            vs[x] = true;
            
            if(x - arr[x] >= 0 && !vs[x - arr[x]]) q.push(x - arr[x]);
            if(x + arr[x] < arr.size() && !vs[x + arr[x]]) q.push(x + arr[x]);
        }
        return false;
    }
};
// @lc code=end

