/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
public:
    vector<int> W;
    int total;
    
    Solution(vector<int>& w) {
        W.resize(w.size());
        W[0] = w[0];
        for(int i = 1; i < w.size(); i++) {
            W[i] = w[i] + W[i-1];
        }
        total = W[W.size()-1];
    }
    
    int pickIndex() {
        return lower_bound(W.begin(), W.end(), (rand() % total)+1) - W.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

