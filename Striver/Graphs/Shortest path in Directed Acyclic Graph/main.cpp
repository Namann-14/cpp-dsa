#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<pair<int, int>>>mp;
    stack<int>s;
    void pop(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            mp[u].push_back({v, w});
        }
    }
    void dfs(int node, vector<bool>& vis) {
        vis[node] = 1;
        for (auto nbr : mp[node]) {
            if (!vis[nbr.first]) {
                dfs(nbr.first, vis);
            }
        }
        s.push(node);
    }
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        pop(edges);
        vector<bool>vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) dfs(i, vis);
        } 
        vector<int>dist(V, 1e9);
        dist[0] = 0;
        while (!s.empty()) {
            int node = s.top();
            s.pop();

            for (auto nbr : mp[node]) {
                int v = nbr.first;
                int wt = nbr.second;

                if (dist[node] != 1e9 && dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                } 
            }
        }
        return dist;
    }
};
