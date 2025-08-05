// https://www.geeksforgeeks.org/problems/topological-sort/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        unordered_map<int, vector<int>>mp;
        stack<int>s;
        void populate(vector<vector<int>>& edges) {
            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                mp[u].push_back(v);
            }
        }
        void solve(int node, vector<bool>& vis) {
            vis[node] = 1;
            for (auto neighbour : mp[node]) {
                if (!vis[neighbour]) {
                    solve(neighbour, vis);
                }
            }
            s.push(node);
        }
        public:
        vector<int> topoSort(int n, vector<vector<int>>& edges) {
            populate(edges);
            vector<bool>vis(n, 0);
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    solve(i, vis);
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
