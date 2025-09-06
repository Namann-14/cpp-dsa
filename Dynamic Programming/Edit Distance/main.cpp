// https://leetcode.com/problems/edit-distance/description/
#include <bits/stdc++.h>
using namespace std;

// Memo
class Solution {
private:
    int solve(int i, int j, const string& a, const string& b, vector<vector<int>>& dp) {
        if (i >= a.size()) return b.size() - j;
        if (j >= b.size()) return a.size() - i;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if (a[i] == b[j]) {
            return solve(i + 1, j + 1, a, b, dp);
        } else {
            // insert
            int ins = 1 + solve(i, j + 1, a, b, dp);
            // delete
            int del = 1 + solve(i + 1, j, a, b, dp);
            // replace
            int rep = 1 + solve(i + 1, j + 1, a, b, dp);

            ans = min({ins, del, rep});  
        }
        return dp[i][j] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return solve(0, 0, word1, word2, dp);
    }
};

// Tab
class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		// Base cases
		for (int i = 0; i <= n; i++) dp[i][0] = i; // delete all
		for (int j = 0; j <= m; j++) dp[0][j] = j; // insert all

		// Bottom-up fill
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				} else {
					int ins = 1 + dp[i][j - 1];
					int del = 1 + dp[i - 1][j];
					int rep = 1 + dp[i - 1][j - 1];
					dp[i][j] = min({ins, del, rep});
				}
			}
		}
		return dp[n][m];
	}
};



// SO
class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();

		vector<int> prev(m + 1, 0), curr(m + 1, 0);

		// Base case for first row (word1 = "")
		for (int j = 0; j <= m; j++) prev[j] = j;

		for (int i = 1; i <= n; i++) {
			curr[0] = i; // base case for first column (word2 = "")
			for (int j = 1; j <= m; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					curr[j] = prev[j - 1];
				} else {
					int ins = 1 + curr[j - 1];
					int del = 1 + prev[j];
					int rep = 1 + prev[j - 1];
					curr[j] = min({ins, del, rep});
				}
			}
			prev = curr;
		}
		return prev[m];
	}
};
