#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int color, vector<int>& vis, vector<vector<int>>& graph) {
        vis[node] = color;
        for (auto nbr : graph[node]) {
            if (vis[nbr] == -1) {
                if (!dfs(nbr, 1 - color, vis, graph)) return false;
            } else if (vis[nbr] == color) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, -1);
        for (int i = 0;  i < n; i++) {
            if (vis[i] == - 1 && !dfs(i, 0, vis, graph)) return false;
        }
        return true;
    }
};