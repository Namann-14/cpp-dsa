// https://leetcode.com/problems/maximal-square/
#include <bits/stdc++.h>
using namespace std;

// Top Down
class Solution {
private:
    int maxi = 0;
    int solve(int x, int y, int m, int n, vector<vector<char>>& mat, vector<vector<int>>& dp) {
        if (x >= m || y >= n) return 0;
        if (dp[x][y] != -1) return dp[x][y];

        int right = solve(x, y + 1, m, n, mat, dp);
        int down = solve(x + 1, y, m, n, mat, dp);
        int diag = solve(x + 1, y + 1, m, n, mat, dp);

        if (mat[x][y] == '1') {
            dp[x][y] = 1 + min({right, down, diag});
            maxi = max(maxi, dp[x][y]);
            return dp[x][y];
        } else {
            return dp[x][y] = 0;
        }
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                solve(i, j, m, n, matrix, dp);
            }
        }
        return maxi * maxi;
    }
};

// Bottom Up
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = 0;
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int right = dp[i][j + 1];
                int dia = dp[i + 1][j + 1];
                int left = dp[i + 1][j];
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min({left, right, dia});
                    maxi = max(maxi, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return maxi * maxi;
    }
};

// Space Optimized
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = 0;
        vector<int>curr(n + 1, 0);
        vector<int>next(n + 1, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int right = curr[j + 1];
                int dia = next[j + 1];
                int left = next[j];
                if (matrix[i][j] == '1') {
                    curr[j] = 1 + min({left, right, dia});
                    maxi = max(maxi, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return maxi * maxi;
    }
};