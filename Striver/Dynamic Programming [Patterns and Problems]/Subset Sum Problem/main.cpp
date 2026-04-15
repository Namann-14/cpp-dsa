#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:  
    vector<vector<int>>dp;
    int solve(int idx, vector<int>& arr, int sum) {
        if (sum == 0) return 1;
        if (sum < 0) return 0;
        if (idx == arr.size()) return 0;
        if (dp[idx][sum] != -1) return dp[idx][sum];
        int newSum = sum - arr[idx];
        return dp[idx][sum] = solve(idx + 1, arr, newSum) || solve(idx + 1, arr, sum);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        dp.assign(arr.size() + 1, vector<int>(sum + 1, -1));
        return solve(0, arr, sum);
    }
};