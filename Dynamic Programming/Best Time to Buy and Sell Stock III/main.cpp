// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, n, prices, dp);
    }
};

// Tab
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (buy == 1) {
                        int take = -prices[idx] + dp[idx + 1][0][limit];
                        int notTake = dp[idx + 1][1][limit];
                        profit = max(take, notTake);
                    } else {
                        int take = prices[idx] + dp[idx + 1][1][limit - 1];
                        int notTake = dp[idx + 1][0][limit];
                        profit = max(take, notTake);
                    }
                    dp[idx][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};


// SO
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // next[buy][limit], curr[buy][limit]
        vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (buy == 1) {
                        int take = -prices[idx] + next[0][limit];   // buy → move to sell
                        int notTake = next[1][limit];               // skip
                        profit = max(take, notTake);
                    } else {
                        int take = prices[idx] + next[1][limit - 1]; // sell → consume 1 transaction
                        int notTake = next[0][limit];                // skip
                        profit = max(take, notTake);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr; // shift for the next iteration
        }

        return next[1][2]; // start with buy allowed & 2 transactions
    }
};
