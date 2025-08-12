// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        void makeSet(int V, vector<int>& parent) {
            for (int i = 0; i < V; i++) {
                parent[i] = i;
            }
        }
        int findParent(vector<int>& parent, int node) {
            if (parent[node] == node) return node;
            return parent[node] = findParent(parent, parent[node]);
        }
        void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
            u = findParent(parent, u);
            v = findParent(parent, v);
            if (rank[u] < rank[v]) {
                parent[u] = v;
            } else if (rank[u] > rank[v]) {
                parent[v] = u;
            } else {
                parent[v] = u;
                rank[u]++;
            }
        }
    public:
        int spanningTree(int V, vector<vector<int>>& edges) {
            sort(edges.begin(), edges.end(), [](vector<int>a, vector<int>b){
                return a[2] < b[2];
            });
            vector<int>parent(V);
            vector<int>rank(V, 0);
            makeSet(V, parent);
            int total = 0;
            for (int i = 0; i < edges.size(); i++) {
                int u = findParent(parent, edges[i][0]);
                int v = findParent(parent, edges[i][1]);
                int wt = edges[i][2];

                if (u != v) {
                    total += wt;
                    unionSet(u, v, parent, rank);
                }
            }
            return total;
        }
};
