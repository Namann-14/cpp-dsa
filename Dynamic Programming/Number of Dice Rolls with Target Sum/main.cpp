// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
#include <bits/stdc++.h>
using namespace std;

// Memo
class Solution {
private:
    const int MOD = 1e9 + 7;
    long long solve(int dice, int face, int target, vector<vector<int>>&dp) {
        if (target < 0) return 0;
        if (dice == 0 && target != 0) return 0;
        if (dice != 0 && target == 0) return 0;
        if (dice == 0 && target == 0) return 1;
        if (dp[dice][target] != -1) return dp[dice][target];
        long long ans = 0;
        for (int i = 1; i <= face; i++) {
            ans = (ans + solve(dice - 1, face, target - i, dp)) % MOD;
        }
        return dp[dice][target] = (int)ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};

// Tab
class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int dice = 1; dice <= n; dice++) {
            for (int sum = 1; sum <= target; sum++) {
                long long ways = 0;
                for (int face = 1; face <= k; face++) {
                    if (sum - face >= 0) {
                        ways = (ways + dp[dice - 1][sum - face]) % MOD;
                    }
                }
                dp[dice][sum] = (int)ways;
            }
        }
        return dp[n][target];
    }
};

// SO
class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        // base case: 0 dice → sum = 0
        prev[0] = 1;

        for (int dice = 1; dice <= n; dice++) {
            fill(curr.begin(), curr.end(), 0); // reset for this dice
            for (int sum = 1; sum <= target; sum++) {
                long long ways = 0;
                for (int face = 1; face <= k; face++) {
                    if (sum - face >= 0) {
                        ways = (ways + prev[sum - face]) % MOD;
                    }
                }
                curr[sum] = (int)ways;
            }
            prev = curr; // move forward
        }

        return prev[target];
    }
};
