// https://www.geeksforgeeks.org/problems/longest-path-in-a-directed-acyclic-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    unordered_map<int, vector<pair<int, int>>>mp;
    stack<int>s;
    void pop(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            mp[u].push_back({v, w});
        }
    }
    void dfs(int node, vector<bool>& vis) {
        vis[node] = 1;
        for (auto [nbr, w] : mp[node]) {
            if (!vis[nbr]){
                dfs(nbr, vis);
            }
        }
        s.push(node);
    }
  public:
    vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src) {
        pop(edges);
        vector<bool>vis(v, false);
        for (int i = 0 ; i < v; i++) {
            if (!vis[i]) {
                dfs(i, vis);
            }
        }
        vector<int>dis(v, INT_MIN);
        dis[src] = 0;
        while (!s.empty()) {
            int node = s.top();
            s.pop();
            for (auto nbr : mp[node]) {
                int v = nbr.first;
                int w = nbr.second;
                
                if (dis[node] != INT_MIN && dis[v] < dis[node] + w) {
                    dis[v] = dis[node] + w;
                }

            }
        }
        
        return dis;
        
    }
};