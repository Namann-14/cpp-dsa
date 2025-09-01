// https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Top Down with Memoisation
    int solve(int amt, vector<int>& nums, vector<int>& dp) {
        if (amt == 0) return 0;             
        if (amt < 0) return INT_MAX;        
        if (dp[amt] != -1) return dp[amt];

        int mini = INT_MAX;
        for (int coin : nums) {
            int res = solve(amt - coin, nums, dp);
            if (res != INT_MAX) {
                mini = min(mini, res + 1);
            }
        }
        return dp[amt] = mini;
    }

    // Bottom Up Tabulation
    int solve2(vector<int>& coins, int amt) {
        vector<int>dp(amt + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amt; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amt] == INT_MAX ? -1 : dp[amt];
    }

    // Space Optimization is not possible because the fn(n) does not depend directly on the prev calc values.
public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount + 1, -1);
        // int ans = solve(amount, coins, dp);
        // return ans == INT_MAX ? -1 : ans;
        return solve2(coins, amount);
    }
};
