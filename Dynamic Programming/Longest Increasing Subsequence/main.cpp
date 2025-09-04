// https://leetcode.com/problems/longest-increasing-subsequence/
#include <bits/stdc++.h>
using namespace std;

// Memo
class Solution {
private:
    int solve(int curr, int prev, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if (curr >= n) return 0;
        if (dp[curr][prev + 1] != -1) return dp[curr][prev + 1];

        // take
        int incl = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            incl = 1 + solve(curr + 1, curr, n, nums, dp);
        }
        // not take
        int excl = 0 + solve(curr + 1, prev, n, nums, dp);

        dp[curr][prev + 1] =  max(incl, excl);
        return dp[curr][prev + 1];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, -1, n, nums, dp);
    }
};

// Tab
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int incl = 0;
                if (prev == -1 || nums[curr] > nums[prev]) {
                    incl = 1 + dp[curr + 1][curr + 1];
                }
                int excl = dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(incl, excl);
            }
        }
        return dp[0][0];
    }
};

// Space
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0), curr(n + 1, 0);

        for (int currIdx = n - 1; currIdx >= 0; currIdx--) {
            for (int prevIdx = currIdx - 1; prevIdx >= -1; prevIdx--) {
                int incl = 0;
                if (prevIdx == -1 || nums[currIdx] > nums[prevIdx]) {
                    incl = 1 + next[currIdx + 1];
                }
                int excl = next[prevIdx + 1];
                curr[prevIdx + 1] = max(incl, excl);
            }
            next = curr;
        }

        return next[0];
    }
};

// Dp with binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int>ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } else {
                int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }
};