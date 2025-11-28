#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>>mp;
    void pop(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }
    }
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        pop(edges);
        vector<int>dist(V, 1e9);
        dist[src] = 0;
        queue<int>q;
        q.push(src);
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            for (auto nbr : mp[front]) {
                if (dist[front] + 1 < dist[nbr]) {
                    dist[nbr] = dist[front] + 1;
                    q.push(nbr);
                }
            }
        }
        vector<int>ans(V, -1);
        for (int i = 0 ; i < V; i++) {
            if (dist[i] != 1e9) ans[i] = dist[i];
        }
        return ans;
    }
};
