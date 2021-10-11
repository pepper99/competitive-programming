/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class TrieNode {
public:
    TrieNode *children[26];
    bool end;
    
    TrieNode() {
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        end = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *crawl = root;
        for(int i = 0; i < word.length(); i++) {
            int id = word[i]-'a';
            if(!crawl->children[id]) crawl->children[id] = new TrieNode();
            crawl = crawl->children[id];
        }
        crawl->end = true;
    }
    
    bool search(string word) {
        TrieNode *crawl = root;
        for(int i = 0; i < word.length(); i++) {
            int id = word[i]-'a';
            if(!crawl->children[id]) return false;
            crawl = crawl->children[id];
        }
        return crawl->end == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode *crawl = root;
        for(int i = 0; i < prefix.length(); i++) {
            int id = prefix[i]-'a';
            if(!crawl->children[id]) return false;
            crawl = crawl->children[id];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

