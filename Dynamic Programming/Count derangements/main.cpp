// https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1
#include <bits/stdc++.h>
using namespace std;

// Recursion
class Solution {
    private:

    public:
    int countDer(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        int ans = (n - 1) * (countDer(n - 2) + countDer(n - 1));
        return ans;
    }
};

// Top Down Memoization
class Solution {
    private:
        int solve(int n, vector<int>& dp) {
            if (n == 1) return 0;
            if (n == 2) return 1;
            if (dp[n] != -1) return dp[n];
            dp[n] = (n - 1) * (solve(n - 2, dp) + solve(n - 1, dp));
            return dp[n];
        }
    public:
    int countDer(int n) {
        vector<int>dp(n + 1, -1);
        return solve(n, dp);
    }
};

// Bottom Up Tab
class Solution {
public:
    int countDer(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;

        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
        }

        return dp[n];
    }
};

// Space Optimization
class Solution {
public:
    int countDer(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;

        int prev2 = 0; // D(1)
        int prev1 = 1; // D(2)
        int curr;

        for (int i = 3; i <= n; i++) {
            curr = (i - 1) * (prev1 + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
