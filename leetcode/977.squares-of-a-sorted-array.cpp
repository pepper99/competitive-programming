/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int j = i-1, k = 0;
        while(k < nums.size()) {;
            if(i < nums.size()) {
                if(j >= 0) {
                    if(-nums[j] > nums[i]) {
                        ans[k] = nums[i]*nums[i];
                        i++;
                    }
                    else {
                        ans[k] = nums[j]*nums[j];
                        j--;
                    }
                }
                else {
                    ans[k] = nums[i]*nums[i];
                    i++;
                }
            }
            else if(j >= 0) {
                ans[k] = nums[j]*nums[j];
                j--;
            }
            else break;
            k++;
        }
        return ans;
    }
};
// @lc code=end

