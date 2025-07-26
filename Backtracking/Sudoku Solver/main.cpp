// https://leetcode.com/problems/sudoku-solver/submissions/1712545887/
class Solution {
private:
    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val) return false;
            if (board[row][i] == val) return false;
            if (board[3*(row/3) + i/3][3*(col/3) + i%3] == val) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (isSafe(i, j, board, val)) {
                            board[i][j] = val;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true; 
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
