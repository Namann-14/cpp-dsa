// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// uning pq
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
            mp[v].push_back({u, w});
        }
    }

public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        populate(edges);
        vector<bool>vis(V, false);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0, 0});
        int total = 0;
        while (!pq.empty()) {
            auto [w, node] = pq.top();
            pq.pop();

            if (vis[node]) continue;
            vis[node] = 1;
            total += w;

            for (auto &[v, wt] : mp[node]) {
                if (!vis[v]) {
                    pq.push({wt, v});
                }
            }
        }

        return total;
    }
};

