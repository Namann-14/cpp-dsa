// https://leetcode.com/problems/longest-palindromic-subsequence/
#include <bits/stdc++.h>
using namespace std;

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
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>>dp(s.size() + 1, vector<int>(s.size() + 1, -1));
        return solve(0, 0, s, rev, dp);
    }
};