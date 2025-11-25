#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>>mp;
    void pop(int V, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
    }
    bool dfs(int node, int parent, vector<bool>& vis) {
        vis[node] = 1;
        for (int nbr : mp[node]) {
            if (!vis[nbr]) {
                bool ans = dfs(nbr, node, vis);
                if (ans) return true;
            } else if (nbr != parent) return true;
        }
        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        pop(V, edges);
        vector<bool>vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                bool ans = dfs(i, -1, vis);
                if (ans) return true;
            }
        }
        return false;
    }
};