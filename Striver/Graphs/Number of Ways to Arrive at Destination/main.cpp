#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const long long MOD = 1e9 + 7;
    unordered_map<int, vector<pair<int, int>>> mp;

    void pop(vector<vector<int>>& edges) {
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            mp[u].push_back({v, wt});
            mp[v].push_back({u, wt});
        }
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        pop(roads);

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &it : mp[node]) {
                int nbr = it.first;
                long long wt = it.second;

                if (dist[nbr] > d + wt) {
                    dist[nbr] = d + wt;
                    pq.push({dist[nbr], nbr});

                    ways[nbr] = ways[node]; // new shortest path found
                }
                else if (dist[nbr] == d + wt) {
                    ways[nbr] = (ways[nbr] + ways[node]) % MOD;  // another shortest path
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};
