/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int dp[matrix.size()][matrix[0].size()];
        memset(dp,0,sizeof dp);
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                dp[i][j] = 1 + 
                ans = max(ans,dfs(i,j,1,matrix,mx));
            }
        }
        return ans;
    }
    
    int dfs(int i, int j, int c, vector<vector<int>>& matrix, vector<vector<int>> &mx) {
        int ans = c;
        int temp = matrix[i][j];
        matrix[i][j] = -1;
        for(int k = 0; k < 4; k++) {
            int x = i+dir[k][0], y = j+dir[k][1];
            if(0 <= x && x < matrix.size() && 0 <= y && y < matrix[x].size() && temp < matrix[x][y]) {
                if(mx[x][y] != -1) ans = max(ans,c + mx[x][y]);
                else ans = max(ans,dfs(x,y,c+1,matrix,mx));
            }
        }
        matrix[i][j] = temp;
        mx[i][j] = ans - c + 1;
        return ans;
    }
};
// @lc code=end

