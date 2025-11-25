#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>>mp;
    stack<int>s;
    void pop(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            mp[u].push_back(v);
        }
    }
    void dfs(int node, vector<bool>& vis) {
        vis[node] = 1;
        for (auto nbr : mp[node]) {
            if (!vis[nbr]) {
                dfs(nbr, vis);
            }
        }
        s.push(node);
    }
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        pop(edges);
        vector<bool>vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis);
            }
        }
        vector<int>ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};