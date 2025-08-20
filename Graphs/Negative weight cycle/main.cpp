// https://www.geeksforgeeks.org/problems/negative-weight-cycle3504/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        vector<int> dist(n, 0);
        for (int i = 1; i < n; i++) {
            for (auto edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] + w < dist[v]) {
                return 1;
            }
        }

        return 0;
    }
};
