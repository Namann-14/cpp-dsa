#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void bfs(int x, int y, int row, int col, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        queue<pair<int, int>>q;
        q.push({x, y});
        vis[x][y] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            vis[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && !vis[nx][ny] && grid[nx][ny] == '1') {
                    q.push({nx, ny});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>>vis(row, vector<bool>(col, false));

        int count = 0;  
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    bfs(i, j, row, col, vis, grid);
                    count++;
                }
            }
        }

        return count;   
    }
};