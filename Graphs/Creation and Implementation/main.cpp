#include <bits/stdc++.h>
using namespace std;

class graph {
    private:
        unordered_map<int, vector<int>> mp;
    public:
        void add(int a, int b, bool direction) {
            // direction = 0 -> undirected
            // direction = 1 -> directed
            mp[a].push_back(b);
            if (!direction) {
                mp[b].push_back(a);
            }
        }
        void print() {
            for (auto x : mp) {
                cout << x.first << " -> ";
                for (auto y : x.second) {
                    cout << y << " ";
                }
                cout << endl;
            }
        }
};
int main() {
    graph g;
    cout << "=== Graph Implementation Demo ===" << endl;
    // Creating an undirected graph
    cout << "\nCreating undirected graph:" << endl;
    g.add(0, 1, 0);  // 0 -> undirected
    g.add(1, 2, 0);
    g.add(2, 3, 0);
    g.add(3, 0, 0);
    g.add(1, 3, 0);
    
    cout << "Graph structure:" << endl;
    g.print();    
    return 0;
}