/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> vx;
        vector<int> vs;
        vector<vector<string>> v;
        
        // Assigning words to lines
        int sm = 0, current = 0;
        for(int i = 0; i < words.size(); i++) {
            if(sm + words[i].length() + current > maxWidth) {
                vs.push_back(sm);
                sm = 0;
                current = 0;
                v.push_back(vx);
                vx.clear();
            }
            sm += words[i].length();
            current++;
            vx.push_back(words[i]);
        }
        if(current > 0) {
            vs.push_back(sm);
            v.push_back(vx);
            vx.clear();
        }
        
        // Adjusting spaces for each line except the last line
        for(int i = 0; i < v.size() - 1; i++) {
            int spaceLeft = maxWidth - vs[i];
            string s = "";
            // More than one word in the line
            if(v[i].size() > 1) {
                int sp = spaceLeft / (v[i].size() - 1);
                int ex = spaceLeft % (v[i].size() - 1);
                string space(sp, ' ');
                for(int j = 0; j < v[i].size() - 1; j++) {
                    s += v[i][j] + space;
                    if(ex > 0) {
                        s += ' ';
                        ex--;
                    }
                }
                s += v[i][v[i].size() - 1];
            }
            else { // One word in the line
                string space(spaceLeft, ' ');
                s = v[i][0] + space;
            }
            vx.push_back(s);
        }
        
        // Adjusting spaces for the last line
        string s = "";
        string space(maxWidth - vs[vs.size() - 1] - (v[v.size() - 1].size() - 1), ' ');
        for(int i = 0; i < v[v.size() - 1].size() - 1; i++) {
            s += v[v.size() - 1][i] + ' ';
        }
        s += v[v.size() - 1][v[v.size() - 1].size() - 1] + space;
        vx.push_back(s);
        
        return vx;
    }
};
// @lc code=end

