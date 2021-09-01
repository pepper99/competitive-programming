/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol(2);
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(i != j && nums[i] + nums[j] == target){
                    sol[0] = i;
                    sol[1] = j;
                    return sol;
                }
            }
        }
        return sol;
    }
};
// @lc code=end

