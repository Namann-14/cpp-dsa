#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int idx, vector<int>& nums, vector<int>& dp) {
        // mera cost 0 hai in starting stone ka.
        if (idx == 0) return 0;
        if (dp[idx] != -1) return dp[idx];
        int one = solve(idx - 1, nums, dp) + abs(nums[idx] - nums[idx - 1]);
        int two = 1e9;
        if (idx > 1) {
            two = solve(idx - 2, nums, dp) + abs(nums[idx] - nums[idx - 2]);
        }

        return dp[idx] = min(one, two);
    }
public:
    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n + 1, -1);
        return solve(n - 1, nums, dp);
    }
};