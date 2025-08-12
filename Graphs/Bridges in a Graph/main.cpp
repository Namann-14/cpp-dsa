// https://www.naukri.com/code360/problems/bridges-in-graph_893026
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        unordered_map<int, vector<int>>mp;
        vector<vector<int>>res;
        void populate(vector<vector<int>>& edges, int e) {
            for (int i = 0; i < e; i++) {
                int u = edges[i][0];
                int v = edges[i][1];

                mp[u].push_back(v);
                mp[v].push_back(u);
            }
        }
        void dfs(int node, int parent, vector<int>& disc, vector<int>& low, vector<bool>& vis, int& timer) {
            vis[node] = 1;
            disc[node] = low[node] = timer++;
            for (auto nbr : mp[node]) {
                if (nbr == parent) continue;
                if (!vis[nbr]) {
                    dfs(nbr, node, disc, low, vis, timer);
                    low[node] = min(low[node], low[nbr]);

                    if (low[nbr] > disc[node]) {
                        res.push_back({node, nbr});
                    }
                } else {
                    low[node] = min(low[node], disc[nbr]);
                }
            }
        }
    public:
        vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e){
            populate(edges, e);
            vector<int>disc(v, -1);
            vector<int>low(v, -1);
            vector<bool>vis(v, false);
            int parent = -1;
            int timer = 0;
            for (int i = 0; i < v; i++) {
                if (!vis[i]) {
                    dfs(i, parent, disc, low, vis, timer);
                }
            }
            return res;
        }
};
