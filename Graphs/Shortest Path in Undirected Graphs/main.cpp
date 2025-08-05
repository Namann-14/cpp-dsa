// https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<pair<int,int>> edges, int n, int m, int s, int t) {
    vector<vector<int>> adj(n+1);
    for (auto &e : edges) {
        int u = e.first;
        int v = e.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n+1, false);
    vector<int> parent(n+1, -1);
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbour : adj[node]) {
            if (!vis[neighbour]) {
                vis[neighbour] = true;
                parent[neighbour] = node;
                q.push(neighbour);
                if (neighbour == t) break;
            }
        }
    }

    vector<int> path;
    if (!vis[t]) return path;

    for (int curr = t; curr != -1; curr = parent[curr]) {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());
    return path;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges, int n, int m, int s, int t) {
    vector<vector<int>> adj(n+1);
    for (auto &e : edges) {
        int u = e.first;
        int v = e.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n+1, false);
    vector<int> parent(n+1, -1);
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbour : adj[node]) {
            if (!vis[neighbour]) {
                vis[neighbour] = true;
                parent[neighbour] = node;
                q.push(neighbour);
                if (neighbour == t) break;
            }
        }
    }

    vector<int> path;
    if (!vis[t]) return path;

    for (int curr = t; curr != -1; curr = parent[curr]) {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());
    return path;
}
