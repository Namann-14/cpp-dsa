#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> dp;

    int solve(int idx, int target, vector<int>& arr) {
        if (idx == arr.size()) return target == 0 ? 1 : 0;

        if (dp[idx][target] != -1) return dp[idx][target];

        int notTake = solve(idx + 1, target, arr);
        int take = 0;
        if (arr[idx] <= target) take = solve(idx + 1, target - arr[idx], arr);
        return dp[idx][target] = take + notTake;
    }

public:
    int perfectSum(vector<int>& arr, int target) {
        dp.assign(arr.size(), vector<int>(target + 1, -1));
        return solve(0, target, arr);
    }
};
