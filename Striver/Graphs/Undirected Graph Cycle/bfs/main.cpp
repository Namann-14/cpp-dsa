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
    bool bfs(int src, vector<bool>& vis) {
        unordered_map<int, int>parent;
        parent[src] = -1;
        vis[src] = 1;
        queue<int>q;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nbr : mp[node]) {
                if (!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push(nbr);
                    parent[nbr] = node;
                } else if (nbr != parent[node]) {
                    return true;
                }
            }
        }

        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        pop(V, edges);
        vector<bool>vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                bool ans = bfs(i, vis);
                if (ans) return true;
            }
        }
        return false;
    }
};