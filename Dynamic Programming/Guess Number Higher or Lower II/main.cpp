// https://leetcode.com/problems/guess-number-higher-or-lower-ii/
#include <bits/stdc++.h>
using namespace std;

// Memo
class Solution {
private:
    int solve(int start, int end, vector<vector<int>>& dp) {
        if (start >= end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans, i + max(solve(start, i - 1, dp), solve(i + 1, end, dp)));
        }
        return dp[start][end] = ans;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        return solve(1, n, dp);
    }
};

// Tab
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 2; len <= n; len++) {
            for (int start = 1; start + len - 1 <= n; start++) {
                int end = start + len - 1;
                int ans = INT_MAX;
                
                for (int i = start; i <= end; i++) {
                    int cost = i + max(dp[start][i - 1], dp[i + 1][end]);
                    ans = min(ans, cost);
                }
                
                dp[start][end] = ans;
            }
        }        
        return dp[1][n];
    }
};
