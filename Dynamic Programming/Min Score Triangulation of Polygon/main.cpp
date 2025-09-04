// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
#include <bits/stdc++.h>
using namespace std;


// Top Down
class Solution {
private:
    int solve(int start, int end, vector<int>& values, vector<vector<int>>& dp) {
        if (start + 1 == end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        int ans = INT_MAX;
        for (int i = start + 1; i < end; i++) {
            ans = min(ans, values[start] * values[i] * values[end] + solve(start, i, values, dp) + solve(i, end, values, dp));
            dp[start][end] = ans;
        }
        return dp[start][end];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n + 1, vector<int>(n+ 1,-1));
        return solve(0, n - 1, values, dp);
    }
};

// Bottom Up
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
        dp[0][n - 1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                int mini = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    mini = min(mini, values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][n - 1];
    }
};