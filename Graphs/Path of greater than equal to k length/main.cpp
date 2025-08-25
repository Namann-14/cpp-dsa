#include <bits/stdc++.h>
using namespace std;

bool findPath(unordered_map<int, vector<pair<int, int>>> &adj, 
    int src, int k, unordered_map<int, int> &visited) {

    // if k is 0 or negative, return true
    if (k <= 0) return true;

    for(auto i: adj[src]) {

        // adjacnet vertex and weight of edge
        int v = i.first, w = i.second;

        // if vertex v is visited, continue
        if (visited[v] == 1) continue;

        // else include the vertex in path
        visited[v] = 1;

        // if path greater than k is found, return true
        if(findPath(adj, v, k - w, visited))
            return true;

        // backtrack
        visited[v] = 0;
    }

    return false;
}

bool pathMoreThanK(vector<vector<int>> &edgeList, int src, int k) {

    // create an adjacency list representation of the
    // graph
    unordered_map<int, vector<pair<int, int>>> adj;
    for (const auto &edge : edgeList) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // to mark the visited vertices
    unordered_map<int,int> visited;

    // mark source vertex visited
    visited[src] = 1;

    return findPath(adj, src, k, visited);
}

int main() {
    vector<vector<int>> edgeList = {
        {0, 1, 4}, {0, 7, 8}, {1, 7, 11}, 
        {1, 2, 8}, {2, 8, 2}, {8, 6, 6}, 
        {6, 7, 1}, {7, 8, 7}, {2, 3, 7}, 
        {2, 5, 4}, {5, 6, 2}, {3, 5, 14}, 
        {3, 4, 9}, {4, 5, 10}
    };
    int source = 0, k = 58;
    if(pathMoreThanK(edgeList, source, k))
        cout << "Yes";
    else cout << "No";
    return 0;
}