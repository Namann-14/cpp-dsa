#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
    private:
        unordered_map<T, vector<T>>mp;
    public:
        void add(T u, T v, bool direction) {
            mp[u].push_back(v);
            if (!direction) {
                mp[v].push_back(u);
            }
        }
        void print() {
            for (auto x : mp) {
                cout << x.first << " -> ";
                for (auto y : x.second) {
                    cout << y << ", ";
                }
                cout << endl;
            }
        }
        unordered_map<T, vector<T>> getAdjList() {
            return mp;
        }
};

void dfs(unordered_map<int, vector<int>>&mp, unordered_map<int, bool>& vis, vector<int>& temp, int i) {
    temp.push_back(i);
    vis[i] = 1;
    for (auto x : mp[i]) {
        if (!vis[x]) {
            dfs(mp, vis, temp, x);
        }
    }
}

int main() {   
    Graph<int> g;
    g.add(0, 1, 0);
    g.add(1, 2, 0);
    g.add(2, 3, 0);
    g.add(3, 0, 0);
    g.add(1, 3, 0);
    cout << "Graph structure:" << endl;
    g.print(); 

    unordered_map<int, vector<int>> adj = g.getAdjList();
    unordered_map<int, bool> vis;
    vector<vector<int>> ans;

    // Iterate through all nodes in the adjacency list
    for (auto& pair : adj) {
        int node = pair.first;
        if (!vis[node]) {
            vector<int> temp;  // Create temp only when DFS is needed
            dfs(adj, vis, temp, node);
            ans.push_back(temp);  // Add component only if it has nodes
        }
    }

    cout << "DFS Connected Components:" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";  // Print actual values, not indices
        }
        cout << endl;
    }
    
    return 0;
}