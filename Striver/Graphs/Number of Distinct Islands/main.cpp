#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    set<string> s;

    void bfs(int x, int y, int row, int col, vector<vector<bool>>& vis, vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = true;

        vector<pair<int,int>> shape;     // store relative coordinates
        shape.push_back({0, 0});         // starting point

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx >= 0 && nx < row && ny >= 0 && ny < col &&
                    !vis[nx][ny] && grid[nx][ny] == 1) {

                    vis[nx][ny] = true;
                    q.push({nx, ny});

                    // store relative position
                    shape.push_back({nx - x, ny - y});
                }
            }
        }

        // Convert shape vector → string
        string str = "";
        for (auto& p : shape) {
            str += to_string(p.first) + "," + to_string(p.second) + ";";
        }

        s.insert(str);
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    bfs(i, j, row, col, vis, grid);
                }
            }
        }

        return s.size();
    }
};
