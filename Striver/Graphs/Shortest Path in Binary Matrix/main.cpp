#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        if (n == 1) return 1;
        int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        queue<tuple<int, int, int>>q;
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        q.push({0, 0, 1});
        vis[0][0] = 1;
        while (!q.empty()) {
            auto [x, y, dist] = q.front();
            q.pop();

            if (x == n - 1 && y == n - 1) return dist;

            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && !vis[nx][ny]) {
                    q.push({nx, ny, dist + 1});
                    vis[nx][ny] = 1;
                }
            }
        }    
        return -1;
    }
};