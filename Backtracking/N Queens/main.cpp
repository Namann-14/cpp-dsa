// https://leetcode.com/problems/n-queens/
#include<bits/stdc++.h>
class Solution {
private:
    vector<string> add(vector<vector<bool>>& vis, int n) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < n; j++) {
                row += (vis[i][j] ? 'Q' : '.');
            }
            board.push_back(row);
        }
        return board;
    }

    bool isSafe(int row, int col, vector<vector<bool>>& vis, int n) {
        for (int y = col - 1; y >= 0; y--) {
            if (vis[row][y]) return false;
        }
        for (int x = row - 1, y = col - 1; x >= 0 && y >= 0; x--, y--) {
            if (vis[x][y]) return false;
        }
        for (int x = row + 1, y = col - 1; x < n && y >= 0; x++, y--) {
            if (vis[x][y]) return false;
        }
        return true;
    }

    void solve(int col, vector<vector<bool>>& vis, vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(add(vis, n));
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, vis, n)) {
                vis[row][col] = true;
                solve(col + 1, vis, ans, n);
                vis[row][col] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<vector<string>> ans;
        solve(0, vis, ans, n);
        return ans;
    }
};
