// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
#include <bits/stdc++.h>
using namespace std;

// Memo
class Solution {
private:
    int solve(int idx, int buy, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx >= n) return 0;
        if (dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if (buy == 1) {
            int take = -nums[idx] + solve(idx + 1, 0, n, nums, dp);
            int notTake = 0 + solve(idx + 1, 1, n, nums, dp);
            profit = max(take, notTake);
        } else {
            int take = nums[idx] + solve(idx + 1, 1, n, nums, dp);
            int notTake = 0 + solve(idx + 1, 0, n, nums, dp);
            profit = max(take, notTake);
        }
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n + 1, vector<int>(2, -1));
        return solve(0, 1, n, nums, dp);
    }
};

// Tab
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy == 1) {
                    int take = -nums[i] + dp[i + 1][0];
                    int notTake = 0 + dp[i + 1][1];
                    profit = max(take, notTake);
                } else {
                    int take = nums[i] + dp[i + 1][1];
                    int notTake = 0 + dp[i + 1][0];
                    profit = max(take, notTake);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

// SO
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr(2, 0), next(2, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy == 1) { 
                    int take = -nums[i] + next[0];  
                    int notTake = 0 + next[1];      
                    profit = max(take, notTake);
                } else { 
                    int take = nums[i] + next[1];
                    int notTake = 0 + next[0];   
                    profit = max(take, notTake);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};
