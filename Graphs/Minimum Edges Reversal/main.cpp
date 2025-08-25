// https://www.geeksforgeeks.org/problems/minimum-edges/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        unordered_map<int, vector<pair<int, int>>>mp;
        void pop(vector<vector<int>>& edges) {
            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0] - 1;
                int v = edges[i][1] - 1;
                mp[u].push_back({v, 0});
                mp[v].push_back({u, 1});
            }
        }
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
            src--;
            dst--;
            pop(edges);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
            vector<int>dis(n, INT_MAX);
            pq.push({0, src});
            dis[src] = 0;
            while (!pq.empty()) {
                auto [d, node] = pq.top();
                pq.pop();

                if (d > dis[node]) continue;

                for (auto nbr : mp[node]) {
                    int v = nbr.first;
                    int w = nbr.second;
                    if (dis[v] > d + w) {
                        dis[v] = d + w;
                        pq.push({dis[v], v});
                    }
                }
            }
            if (dis[dst] == INT_MAX) return -1;
            return dis[dst];
        }
};
