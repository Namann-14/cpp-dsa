// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
class Solution {
    private:
        unordered_map<int, vector<int>>mp;
        void populate(vector<vector<int>>& edges) {
            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];

                mp[u].push_back(v);
                mp[v].push_back(u);
            }
        }
        bool solve(int src, vector<bool>& vis) {
            unordered_map<int, int>parent;
            parent[src] = -1;
            vis[src] = 1;

            queue<int>q;
            q.push(src);

            while (!q.empty()) {
                int front = q.front();
                q.pop();

                for (auto neighbour : mp[front]) {
                    if (!vis[neighbour]) {
                        vis[neighbour] = 1;
                        q.push(neighbour);
                        parent[neighbour] = front;
                    }
                    else if (neighbour != parent[front]) {
                        return true;
                    }
                }
            }

            return false;
        }
    public:
        bool isCycle(int n, vector<vector<int>>& edges) {
            populate(edges);
            vector<bool>vis(n, 0);
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    bool ans = solve(i, vis);
                    if (ans) return true;
                }
            }
            return false;
        }
};