// https://www.geeksforgeeks.org/problems/topological-sort/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        unordered_map<int, vector<int>>mp;
        stack<int>s;
        void populate(vector<vector<int>>& edges) {
            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                mp[u].push_back(v);
            }
        }
    public:
        vector<int> topoSort(int n, vector<vector<int>>& edges) {
            populate(edges);
            vector<int>indgree(n);
            vector<int>ans;
            for (auto x : mp) {
                for (auto y : x.second) {
                    indgree[y]++;
                }
            }
            queue<int>q;
            for (int i = 0; i < n; i++) {
                if (indgree[i] == 0) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int front = q.front();
                q.pop();

                ans.push_back(front);

                for (auto neighbour : mp[front]) {
                    indgree[neighbour]--;
                    if (indgree[neighbour] == 0) {
                        q.push(neighbour);
                    }
                }
            }
            return ans;
        }
};
