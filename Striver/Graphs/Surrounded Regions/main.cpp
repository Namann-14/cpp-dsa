#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int x, int y, int row, int col, vector<vector<char>>& board) {
        if (x < 0 || x >= row || y < 0 || y >= col || board[x][y] != 'O') return;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            dfs(nx, ny, row, col, board);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') dfs(i, 0, row, col, board);
            if (board[i][col - 1] == 'O') dfs(i, 0, row, col, board);
        }

        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O') dfs(i, 0, row, col, board);
            if (board[row - 1][i] == 'O') dfs(i, 0, row, col, board);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                if (board[i][j] == 'O') board[i][j] = 'X';

            }
        }
    }
};