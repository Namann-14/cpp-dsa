// https://www.geeksforgeeks.org/problems/course-schedule/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> adj;
    stack<int> st;

    bool dfs(int node, vector<int>& vis, vector<int>& dfsvis) {
        vis[node] = 1;       
        dfsvis[node] = 1;

        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                if (dfs(nbr, vis, dfsvis)) return true;
            } else if (dfsvis[nbr]) {
                return true;
            }
        }

        dfsvis[node] = 0;  
        st.push(node);
        return false;
    }

public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        for (auto &p : prerequisites) {
            int a = p[0], b = p[1];
            adj[b].push_back(a);
        }
        vector<int> vis(n, 0), dfsvis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, dfsvis)) {
                    return {};
                }
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
