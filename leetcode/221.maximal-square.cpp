/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int dp[n][m];
        int x, ans = 0;
        for(int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0] - '0';
            ans = max(ans,dp[i][0]*dp[i][0]);
        }
        for(int i = 0; i < m; i++) {
            dp[0][i] = matrix[0][i] - '0';
            ans = max(ans,dp[0][i]*dp[0][i]);
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == '1') dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                else dp[i][j] = 0;
                ans = max(ans,dp[i][j]*dp[i][j]);
                cout << dp[i][j] << '\t';
            }
            cout << '\n';
        }
        return ans;
    }
};
// @lc code=end

