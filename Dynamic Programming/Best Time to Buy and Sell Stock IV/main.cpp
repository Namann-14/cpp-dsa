// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include <bits/stdc++.h>
using namespace std;


// Memo
class Solution {
private:
    int solve(int idx, int buy, int limit, int n, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        if (idx >= n) return 0;
        if (limit == 0) return 0;
        if (dp[idx][buy][limit] != -1) return dp[idx][buy][limit];
        int profit = 0;
        if (buy == 1) {
            int take = -nums[idx] + solve(idx + 1, 0, limit, n, nums, dp);
            int notTake = 0 + solve(idx + 1, buy, limit, n, nums, dp);
            profit = max(take, notTake);
        } else {
            int take = nums[idx] + solve(idx + 1, 1, limit - 1, n, nums, dp);
            int notTake = 0 + solve(idx + 1, buy, limit, n, nums, dp);
            profit = max(take, notTake);
        }
        return dp[idx][buy][limit] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, 1, k, n, prices, dp);
    }
};


