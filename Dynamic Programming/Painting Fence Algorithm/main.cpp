// https://www.geeksforgeeks.org/problems/painting-the-fence3727/1
#include <bits/stdc++.h>
using namespace std;

// Recursion
class Solution {
    private:
        int solve(int n, int k) {
            if (n == 1) return k;
            if (n == 2) return pow(k, 2);
            return (solve(n - 2, k) * (k - 1)) + (solve(n - 1, k) * (k - 1));
        }
    public:
        int countWays(int n, int k) {
            return solve(n, k);
        }
};
// Top Down 
class Solution {
    private:
        int solve(int n, int k, vector<int>& dp) {
            if (n == 1) return k;
            if (n == 2) return pow(k, 2);
            if (dp[n] != -1) return dp[n];
            dp[n] = (solve(n - 2, k, dp) * (k - 1)) + (solve(n - 1, k, dp) * (k - 1));
            return dp[n];
        }
    public:
        int countWays(int n, int k) {
            vector<int>dp(n + 1, -1);
            return solve(n, k, dp);
        }
};
// Bottom Up
class Solution {
    private:
        int solve(int n, int k) {
            if (n == 1) return k;
            if (n == 2) return pow(k, 2);
            vector<int>dp(n + 1, -1);
            dp[1] = k;
            dp[2] = pow(k, 2);
            for (int i = 3; i <= n; i++) {
                dp[i] = (dp[i - 2] * (k - 1)) + (dp[i - 1] * (k - 1));
            }
            return dp[n];
        }
    public:
        int countWays(int n, int k) {
            return solve(n, k);
        }
};

// Space Optimization
class Solution {
    private:
        int solve(int n, int k) {
            if (n == 1) return k;
            if (n == 2) return pow(k, 2);
            int prev2 = k;
            int prev1 = pow(k, 2);
            for (int i = 3; i <= n; i++) {
                int curr = (prev2 * (k - 1)) + (prev1 * (k - 1));
                prev2 = prev1;
                prev1 = curr;
            }
            return prev1;
        }
    public:
        int countWays(int n, int k) {
            return solve(n, k);
        }
};
