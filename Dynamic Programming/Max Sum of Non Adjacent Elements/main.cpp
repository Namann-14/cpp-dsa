// https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        // Top Down Recurrsion + Memoization
        int solve(int n, vector<int>& nums, vector<int>& dp) {
            if (n == 0) return nums[0];
            if (n < 0) return 0;
            if (dp[n] != -1) return dp[n];

            int incl = solve(n - 2, nums, dp) + nums[n];
            int excl = solve(n - 1, nums, dp) + 0;

            dp[n] = max(incl, excl);

            return dp[n];

        }
        // Bottom Up -> Tabulation
        int solveTab(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return nums[0];

            vector<int> dp(n, 0);
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);

            for (int i = 2; i < n; i++) {
                int incl = dp[i - 2] + nums[i];
                int excl = dp[i - 1];
                dp[i] = max(incl, excl);
            }
            return dp[n - 1];
        }
        // Space Optimization
        int solveOpt(vector<int>& nums) {
            int n = nums.size();
            int prev2 = nums[0];
            int prev1 = max(nums[1], nums[0]);

            for (int i = 2; i < n; i++) {
                int incl = prev2 + nums[i];
                int excl = prev1;
                
                int curr = max(incl, excl);

                prev2 = prev1;
                prev1 = curr;
            }

            return prev1;
        }
    public:
    int findMaxSum(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n + 1, -1);
        // return solve(n - 1, nums, dp);
        return solveOpt(nums);
    }
};
