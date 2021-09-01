#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    public:
        vector<vector<int>> g;
        int n;
    
        Graph(int n) {
            g.resize(n);
            g.clear();
            this->n = n;
        }
    
        void add_edge(int u, int v) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            vector<int> dist(n, -1);
            queue<pair<int, int>> q;
            q.push({start, 0});
            pair<int, int> p;
            while(!q.empty()) {
                p = q.front();
                q.pop();
                if(dist[p.first] != -1) continue;
                dist[p.first] = p.second;
                
                for(int &x : g[p.first]) {
                    if(dist[x] == -1) q.push({x, p.second + 6});
                }
            }
            return dist;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
