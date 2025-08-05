// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include <bits/stdc++.h>
using namespace std;
class Solution {
    private:
        unordered_map<int, vector<int>>mp;
        void populate(vector<vector<int>>& edges) {
            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];

                // directed graph
                mp[u].push_back(v);
            }
        }
        bool solve(int node, vector<bool>& vis, vector<bool>& dfsvis) {
            vis[node] = 1;
            dfsvis[node] = 1;
            for (auto neighbour : mp[node]) {
                if (!vis[neighbour]) {
                   bool cycleDetected =  solve(neighbour, vis, dfsvis);
                   if (cycleDetected) return true;
                } else if (dfsvis[neighbour]) {
                    return true;
                }
            }
            dfsvis[node] = 0;
            return false;
        }
    public:
        bool isCyclic(int n, vector<vector<int>>& edges) {
            populate(edges);
            vector<bool>vis(n, 0);
            vector<bool>dfsvis(n, 0);
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    bool ans = solve(i, vis, dfsvis);
                    if (ans) return true;
                }
            }
            return false;
        } 
};