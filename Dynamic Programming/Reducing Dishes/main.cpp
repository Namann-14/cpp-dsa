// 
#include <bits/stdc++.h>
using namespace std;

// Memo
class Solution {
private:
    int solve(int idx, int time, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx >= n) return 0;
        if (dp[idx][time] != -1) return dp[idx][time];
        int incl = nums[idx] * (time + 1) + solve(idx + 1, time + 1, n, nums, dp);
        int excl = 0 + solve(idx + 1, time, n, nums, dp);
        dp[idx][time] = max(incl, excl);
        return dp[idx][time];
    } 
public:
    int maxSatisfaction(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, 0, n, nums, dp);
    }
};

// Tab
class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Fill from bottom-up
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int time = idx; time >= 0; time--) {
                int incl = nums[idx] * (time + 1) + dp[idx + 1][time + 1];
                int excl = dp[idx + 1][time];
                dp[idx][time] = max(incl, excl);
            }
        }

        return dp[0][0];
    }
};

// Space 
class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> next(n + 1, 0), curr(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int time = idx; time >= 0; time--) {
                int incl = nums[idx] * (time + 1) + next[time + 1];
                int excl = next[time];
                curr[time] = max(incl, excl);
            }
            next = curr;
        }

        return next[0];
    }
};


// Space Better
class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int time = idx; time >= 0; time--) {
                int incl = nums[idx] * (time + 1) + dp[time + 1];
                int excl = dp[time];
                dp[time] = max(incl, excl);
            }
        }

        return dp[0];
    }
};
