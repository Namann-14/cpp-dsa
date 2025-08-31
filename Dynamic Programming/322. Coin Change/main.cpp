// https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
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
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = solve(amount, coins, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
