/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int x[10]; memset(x,0,sizeof x);
        int b = 0, c = 0;
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) b++;
            else x[secret[i]-'0']++;
        }
        for(int i = 0; i < guess.length(); i++) {
            if(secret[i] != guess[i] && x[guess[i]-'0'] > 0) {
                x[guess[i]-'0']--;
                c++;
            }
        }
        return to_string(b) + 'A' + to_string(c) + 'B';
    }
};
// @lc code=end

