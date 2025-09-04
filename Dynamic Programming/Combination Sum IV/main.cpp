// https://leetcode.com/problems/combination-sum-iv/submissions/1758686554/
#include <bits/stdc++.h>
using namespace std;

// Top Donw
class Solution {
private:
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        if (dp[target] != -1) return dp[target];
        int ans = 0;
        for (int num : nums) {
            ans += solve(nums, target - num, dp);
        }
        dp[target] = ans;
        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};

// Bottom Up
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                    if (dp[i] > INT_MAX) dp[i] = INT_MAX;
                }
            }
        }
        return (int)dp[target];
    }
};