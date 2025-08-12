// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:

    public:
        int bellmanFord(int V, vector<vector<int>>& edges, int src) {
            vector<int>dist(V, 1e9);
            dist[src] = 0;
            for (int i = 1; i <= V; i++) {
                for (auto edge : edges) {
                    int u = edge[0];
                    int v = edge[2];
                    int wt = edge[1];

                    if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
            for (auto edge : edges) {
                int u = edge[0];
                int v = edge[2];
                int wt = edge[1];

                if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                    return -1;
                }
            }
            
            return dist[V - 1];
        }
};
