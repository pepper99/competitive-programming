/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class TrieNode {
public:
    TrieNode* children[26];
    bool end;
        
    TrieNode() {
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        end = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode;
    }
    
    void addWord(string &word) {
        TrieNode* crawl = root;
        for(char &c : word) {
            if(!crawl->children[c - 'a']) crawl->children[c-'a'] = new TrieNode;
            crawl = crawl->children[c-'a'];
        }
        crawl->end = true;
    }
};

class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string &s : words) trie.addWord(s);
        TrieNode* crawl = trie.root;
        vector<string> ans;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++) {
                if(crawl->children[board[i][j]-'a']) {
                    cout << board[i][j] << '\n';
                    dfs(i,j,"",board,ans,crawl->children[board[i][j]-'a']);
                }
            }
        return ans;
    }
    
    void dfs(int i, int j, string s, vector<vector<char>>& board, vector<string> &ans, TrieNode* crawl) {
        s += board[i][j];
        char t = board[i][j];
        board[i][j] = '-';
        if(crawl->end) {
            ans.push_back(s);
            crawl->end = false;
        }
        for(int k = 0; k < 4; k++) {
            int x = i+dir[k][0], y = j+dir[k][1];
            if(0 <= x && x < board.size() && 0 <= y && y < board[x].size() && board[x][y] != '-' && crawl->children[board[x][y]-'a']) {
                dfs(x,y,s,board,ans,crawl->children[board[x][y]-'a']);
            }
        }
        board[i][j] = t;
    }
};
// @lc code=end

