#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    vector<vector<int>> dp;
    int solve(int idx, int act, vector<vector<int>>& nums) {
        if (dp[idx][act] != -1) return dp[idx][act];
        if (idx == 0) {
            int maxi = 0;
            for (int i = 0; i < 3; i++) {
                if (i != act) {
                    maxi = max(maxi, nums[0][i]);
                }
            }
            return dp[idx][act] = maxi;
        }
        int maxi = 0;
        for (int i = 0; i < 3; i++) {
            if (i != act) {
                maxi = max(maxi, nums[idx][i] + solve(idx - 1, i, nums));
            }
        }
        return dp[idx][act] = maxi;
    }

  public:
    int maximumPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(4, -1));
        return solve(n - 1, 3, nums);
    }
};
