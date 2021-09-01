/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<int, Node*> g;
        unordered_map<int, vector<int>> ajl;
        genList(ajl, node);
        for(auto &p : ajl) g[p.first] = new Node(p.first);
        for(auto &p : ajl) {
            for(int &x : ajl[p.first]) {
                g[p.first]->neighbors.push_back(g[x]);
            }
        }
        return g[node->val];
    }
    
    void genList(unordered_map<int, vector<int>> &ajl, Node* node) {
        ajl.emplace(node->val, vector<int>());
        for(Node* n : node->neighbors) {
            ajl[node->val].push_back(n->val);
            if(ajl.find(n->val) == ajl.end()) {
                genList(ajl, n);
            }
        }
    }
};
// @lc code=end

