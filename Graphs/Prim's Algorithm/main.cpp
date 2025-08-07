// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
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

        vector<int> key(V, INT_MAX);     // Store minimum edge weight to reach each node
        vector<bool> mst(V, false);      // MST inclusion flag
        vector<int> parent(V, -1);       // Store MST parent (optional, if needed)

        key[0] = 0; // Start from vertex 0
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++) {
            int mini = INT_MAX;
            int u = -1;

            // Find the minimum key vertex not yet included in MST
            for (int v = 0; v < V; v++) {
                if (!mst[v] && key[v] < mini) {
                    mini = key[v];
                    u = v;
                }
            }

            mst[u] = true; // Include u in MST

            // Update key values of adjacent vertices of u
            for (auto& [v, weight] : mp[u]) {
                if (!mst[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }

        // Sum up the weights in the MST
        int totalWeight = 0;
        for (int i = 0; i < V; i++) {
            totalWeight += key[i];
        }

        return totalWeight;
    }
};

