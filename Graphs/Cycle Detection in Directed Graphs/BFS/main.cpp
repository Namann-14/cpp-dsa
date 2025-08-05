// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        unordered_map<int, vector<int>>mp;
        void populate(vector<vector<int>>& edges) {
            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];

                // directed graph
                mp[u].push_back(v);
            }
        }
    public:
        bool isCyclic(int n, vector<vector<int>> &edges) {
            populate(edges);
            vector<int>indegree(n);
            for (auto x : mp) {
                for (auto y : x.second) {
                    indegree[y]++;
                }
            }
            queue<int>q;
            for (int i = 0; i < n; i++) {
                if (indegree[i]==0) {
                    q.push(i);
                }
            }
            int count = 0;
            while (!q.empty()) {
                int front = q.front();
                q.pop();
                count++;
                for (int neighbour : mp[front]) {
                    indegree[neighbour]--;
                    if (indegree[neighbour] == 0) {
                        q.push(neighbour);
                    }
                }
            }

            return count != n;
        }
};
