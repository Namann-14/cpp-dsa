#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<bool>& vis, stack<int>& s, vector<vector<int>>& adj) {
        vis[node] = true;
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                dfs(nbr, vis, s, adj);
            }
        }
        s.push(node); // store by finish time
    }

    void revDfs(int node, vector<bool>& vis, vector<vector<int>>& revAdj) {
        vis[node] = true;
        for (auto nbr : revAdj[node]) {
            if (!vis[nbr]) {
                revDfs(nbr, vis, revAdj);
            }
        }
    }

public:
    int kosaraju(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> vis(V, false);
        stack<int> s;

        // Step 1: DFS on original graph to fill stack
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, s, adj);
            }
        }

        // Step 2: Reverse the graph
        vector<vector<int>> revAdj(V);
        for (int u = 0; u < V; u++) {
            for (auto v : adj[u]) {
                revAdj[v].push_back(u);
            }
        }

        // Step 3: DFS on reversed graph
        fill(vis.begin(), vis.end(), false);
        int sccCount = 0;

        while (!s.empty()) {
            int node = s.top();
            s.pop();
            if (!vis[node]) {
                sccCount++;
                revDfs(node, vis, revAdj);
            }
        }

        return sccCount;
    }
};
