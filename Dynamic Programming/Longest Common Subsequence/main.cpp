// https://leetcode.com/problems/longest-common-subsequence/
#include <bits/stdc++.h>
using namespace std;


// Memo
class Solution {
private:
    int solve(int i, int j, const string& text1, const string& text2, vector<vector<int>>& dp) {
        if (i >= text1.size() || j >= text2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, text1, text2, dp);
        } else {
            return dp[i][j] = max(solve(i + 1, j, text1, text2, dp), solve(i, j + 1, text1, text2, dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, text1, text2, dp);
    }
};


// Tab
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};

// SO
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> curr(m + 1, 0), next(m + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr;
        }

        return next[0];
    }
};
