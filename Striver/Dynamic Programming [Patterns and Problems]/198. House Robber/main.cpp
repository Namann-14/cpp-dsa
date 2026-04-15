#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    vector<int>dp;
    int solve(int idx, int n, vector<int>& nums) {
        if (idx == 0) return nums[idx];
        if (idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];
        int incl = solve(idx - 2, n, nums) + nums[idx];
        int excl = solve(idx - 1, n, nums);

        return dp[idx] = max(incl, excl);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n + 1, -1);
        return solve(n - 1, n, nums);
    }
};