#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<pair<int, int>>>mp;
    void pop(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            mp[u].push_back({v, wt});
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int src) {
        pop(edges);
        vector<int>dist(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
        dist[src] = 0;
        pq.push({0, src});
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
        int maxi = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};