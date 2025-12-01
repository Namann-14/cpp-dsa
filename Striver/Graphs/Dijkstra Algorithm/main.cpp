#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<pair<int,int>>>mp;
    void pop(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }
    }
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        pop(edges);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>dist(V, 1e9);
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto [nbr, wt] : mp[node]) {
                if (dist[nbr] > d + wt) {
                    dist[nbr] = d + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return dist;
    }
};