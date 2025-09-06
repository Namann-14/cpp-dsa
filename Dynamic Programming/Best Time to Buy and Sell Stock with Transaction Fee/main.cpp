// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
#include <bits/stdc++.h>
using namespace std;

// Memo
class Solution {
private:
    long long solve(int idx, int buy, int fees, int n, vector<int>& nums, vector<vector<long long>>& dp) {
        if (idx >= n) return 0;
        if (dp[idx][buy] != -1) return dp[idx][buy];

        long long profit = 0;
        if (buy == 1) {
            long long take = -nums[idx] + solve(idx + 1, 0, fees, n, nums, dp);
            long long notTake = solve(idx + 1, 1, fees, n, nums, dp);
            profit = max(take, notTake);
        } else {
            long long take = nums[idx] - fees + solve(idx + 1, 1, fees, n, nums, dp);
            long long notTake = solve(idx + 1, 0, fees, n, nums, dp);
            profit = max(take, notTake);
        }

        return dp[idx][buy] = profit;
    }

public:
    long long maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, 1, k, n, prices, dp);
    }
};
