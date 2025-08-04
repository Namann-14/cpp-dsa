#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
    private:
        unordered_map<T, vector<T>> mp;
    public:
        void add(T u, T v, bool direction) {
            mp[u].push_back(v);
            if (!direction) {
                mp[v].push_back(u);
            }
        }
        void print() {
            for (auto x : mp) {
                cout << x.first << " -> ";
                for (auto y : x.second) {
                    cout << y << ", ";
                }
                cout << endl;
            }
        }
        unordered_map<T, vector<T>> getAdjList() {
            return mp;
        }
};

void bfs(unordered_map<int, vector<int>>& mp, unordered_map<int, bool>& vis, vector<int>& ans, int i) {
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        
        for (auto node : mp[x]) {
            if (!vis[node]) { 
                q.push(node);  
                vis[node] = 1;
            }
        }
    }
}ṅ

int main() {
    Graph<int> g;
    g.add(0, 1, 0);
    g.add(1, 2, 0);
    g.add(2, 3, 0);
    g.add(3, 0, 0);
    g.add(1, 3, 0);
    cout << "Graph structure:" << endl;
    g.print();

    unordered_map<int, vector<int>> adj = g.getAdjList();
    unordered_map<int, bool> vis;
    vector<int> ans;

    int vertex = adj.size();

    for (int i = 0; i < vertex; i++) {
        if (!vis[i]) {
            bfs(adj, vis, ans, i);
        }
    }


    cout << "   BFS   " << endl;

    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}