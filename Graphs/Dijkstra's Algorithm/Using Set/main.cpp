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
            mp[v].push_back({u, w}); // remove if directed graph
        }
    }
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        populate(edges);
        set<pair<int, int>> st;  // (distance, node)
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto it = *st.begin();
            st.erase(st.begin());
            int d = it.first;
            int node = it.second;

            for (auto [adj, wt] : mp[node]) {
                if (dist[adj] > d + wt) {
                    // If node already exists in set, erase old entry
                    if (dist[adj] != INT_MAX)
                        st.erase({dist[adj], adj});
                    dist[adj] = d + wt;
                    st.insert({dist[adj], adj});
                }
            }
        }
        return dist;
    }
};
