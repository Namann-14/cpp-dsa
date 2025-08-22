// https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> mp;
    vector<vector<int>> res;

    void buildGraph(vector<vector<int>>& edges) {
        mp.clear();
        res.clear();
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
    }

    void dfs(int node, int parent, vector<int>& dis, vector<int>& low, vector<bool>& vis, int& timer) {
        vis[node] = 1;
        dis[node] = low[node] = timer++;
        for (auto nbr : mp[node]) {
            if (nbr == parent) continue;
            if (!vis[nbr]) {
                dfs(nbr, node, dis, low, vis, timer);
                low[node] = min(low[node], low[nbr]);

                // Bridge condition
                if (low[nbr] > dis[node]) {
                    res.push_back({node, nbr});
                }
            } else {
                low[node] = min(low[node], dis[nbr]);
            }
        }
    }

public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        buildGraph(edges);

        vector<int> dis(V, -1), low(V, -1);
        vector<bool> vis(V, false);
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, dis, low, vis, timer);
            }
        }

        // check for both directions since graph is undirected
        for (auto &x : res) {
            if ((x[0] == c && x[1] == d) || (x[0] == d && x[1] == c)) {
                return true;
            }
        }
        return false;
    }
};
