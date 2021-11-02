/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
public:
    int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};

    void gameOfLife(vector<vector<int>>& board) {
        int nb[board.size()][board[0].size()];
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                nb[i][j] = 0;
                for(int k = 0; k < 8; k++) {
                    int x = i + dir[k][0], y = j + dir[k][1];
                    if(0 <= x && x < board.size() && 0 <= y && y < board[x].size()) nb[i][j] += board[x][y];
                }
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j]) board[i][j] = (nb[i][j] == 2 || nb[i][j] == 3);
                else board[i][j] = (nb[i][j] == 3);
            }
        }
    }
};
// @lc code=end

