/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> d(n);
        for(int i = 0; i < n; i++) {
            d[i].resize(m);
            for(int j = 0; j < m; j++) d[i][j].resize(k+1,-1);
        }
        
        int w, x, y, z;
        pair<pair<int,int>, pair<int,int>> p;
        queue<pair<pair<int,int>, pair<int,int>>> q;
        q.push({{0,0}, {0,0}});
        while(!q.empty()) {
            p = q.front();
            q.pop();
            x = p.first.first; y = p.first.second; w = p.second.first; z = p.second.second;
            if(d[x][y][z] != -1) continue;
            d[x][y][z] = w;
            if(x == n-1 && y == m-1) return w;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                
                if(z + grid[nx][ny] <= k && d[nx][ny][z + grid[nx][ny]] == -1) q.push({{nx,ny}, {w + 1,z + grid[nx][ny]}});
            }
        }
        return -1;
    }
};
// @lc code=end

