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
        }
    }
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        pop(edges);
        vector<int>indegree(V);
        for (auto x : mp) {
            for (auto y : x.second) {
                indegree[y]++;
            }
        }
        queue<int>q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int>ans;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto nbr : mp[front]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) q.push(nbr);
            }
        }    
        return ans;
    }
};