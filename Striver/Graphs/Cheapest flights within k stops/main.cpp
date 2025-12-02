#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<pair<int, int>>> mp;
    void pop(vector<vector<int>>& edges) {
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            mp[u].push_back({v, w});
        }
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        pop(edges);
        queue<tuple<int, int, int>> q;
        q.push({0, src, 0});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto [stops, node, cost] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto &[nbr, wt] : mp[node]) {
                int newCost = cost + wt;
                if (newCost < dist[nbr]) {
                    dist[nbr] = newCost;
                    q.push({stops + 1, nbr, newCost});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
