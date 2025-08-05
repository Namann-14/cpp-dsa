// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        unordered_map<int, vector<pair<int, int>>>mp;
        stack<int>s;
        void populate(vector<vector<int>>& edges) {
            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                mp[u].push_back({v, w});
            }
        }
        void dfs(int node, vector<bool>& vis) {
            vis[node] = 1;
            for (auto x : mp[node]) {
                if (!vis[x.first]) {
                    dfs(x.first, vis);
                }
            }
            s.push(node);
        }
    public:
        vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
            populate(edges);
            vector<bool>vis(V, 0);
            for (int i = 0; i < V; i++) {
                if (!vis[i]) {
                    dfs(i, vis);
                }
            }
            int src = 0;
            vector<int>dist(V);
            for (int i = 0; i < V; i++) {
                dist[i] = INT_MAX;
            }
            dist[src] = 0;
            while (!s.empty()) {
                int x = s.top();
                s.pop();
                if (dist[x] != INT_MAX) {
                    for (auto neighbour : mp[x]) {
                        if (dist[x] + neighbour.second < dist[neighbour.first]) {
                            dist[neighbour.first] = dist[x] + neighbour.second;
                        }
                    }
                }
            }
            for (int i = 0; i < V; i++) {
                if (dist[i] == INT_MAX) {
                    dist[i] = -1;
                }
            }

            return dist;
        }
};
