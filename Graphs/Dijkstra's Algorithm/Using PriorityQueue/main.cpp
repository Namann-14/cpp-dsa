// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<pair<int, int>>> mp;
    void populate(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            mp[u].push_back({v, w});
        }
    }
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        populate(edges);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto [adj, wt] : mp[node]) {
                if (dist[adj] > d + wt) {
                    dist[adj] = d + wt;
                    pq.push({dist[adj], adj});
                }
            }
        }
        return dist;
    }
};
