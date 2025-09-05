// 
#include <bits/stdc++.h>
using namespace std;

// Memo
class Solution {
private:
    bool solve(int idx, int target, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (idx >= n || target < 0) return false;

        if (dp[idx][target] != -1) return dp[idx][target];

        bool incl = solve(idx + 1, target - nums[idx], n, nums, dp);
        bool excl = solve(idx + 1, target, n, nums, dp);

        return dp[idx][target] = incl || excl;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(0, target, n, nums, dp);
    }
};

// Tab
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= target; j++) {
                bool incl = false;
                if (j - nums[i] >= 0) {
                    incl = dp[i + 1][j - nums[i]];
                }
                bool excl = dp[i + 1][j];
                dp[i][j] = incl || excl;
            }
        }
        return dp[0][target];
    }
};

// SO
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1) return false; // odd sum can't be partitioned
        int target = sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true; // base case: sum 0 is always possible

        for (int num : nums) {
            // iterate backwards to avoid recomputing with same element
            for (int t = target; t >= num; t--) {
                dp[t] = dp[t] || dp[t - num];
            }
        }

        return dp[target];
    }
};
