#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>>mp;
    void pop(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mp[u].push_back(v);
        }
    }
    bool dfs(int node, vector<bool>& vis, vector<bool>& dfsvis) {
        vis[node] = 1;
        dfsvis[node] = 1;

        for (auto nbr : mp[node]) {
            if (!vis[nbr]) {
                bool ans = dfs(nbr, vis, dfsvis);
                if (ans) return true;
            } else if (dfsvis[nbr]) return true;
        }

        dfsvis[node] = 0;
        return false;
    }
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        pop(edges);
        vector<bool>vis(V, false);
        vector<bool>dfsvis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                bool ans = dfs(i, vis, dfsvis);
                if (ans) return true;
            }
        }

        return false;
    }
};