#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>pq;

        vector<vector<int>>dist(row, vector<int>(col, 1e9));
        dist[0][0] = 0;

        pq.push({0, 0, 0});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [diff, x, y]  = pq.top();
            pq.pop();
            if (x == row - 1 && y == col - 1) return diff;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                    int wt = max(abs(heights[x][y] - heights[nx][ny]), diff);
                    if (wt < dist[nx][ny]) {
                        dist[nx][ny] = wt;
                        pq.push({wt, nx, ny});
                    }
                }
            }
        }

        return 0;
    }
};