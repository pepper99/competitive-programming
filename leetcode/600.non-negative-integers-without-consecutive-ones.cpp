/*
 * @lc app=leetcode id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findIntegers(int n) {
        return 1 + rec(1, n); // plus one for number 0
    }
    
    int rec(int i, int n) {
        if(i > n) return 0;
        
        // check last bit
        if(i & 1) { // if last bit is one, we can append only zero
            return 1 + rec(i << 1, n);
        }
        else { // else we can append both one and zero
            return 1 + rec(i << 1, n) + rec((i << 1) + 1, n);
        }
    }
};
// @lc code=end

