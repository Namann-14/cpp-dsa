// https://leetcode.com/problems/longest-arithmetic-subsequence/description/
#include <bits/stdc++.h>
using namespace std;

// Recursion
class Solution {
private:
    int solve(int idx, int diff, vector<int>& nums) {
        if (idx < 0) return 0;
        int ans = 0;
        for (int i = idx; i >= 0; i--) {
            if (nums[idx] - nums[i] == diff) {
                ans = max(ans, 1 + solve(i, diff, nums));
            }
        }
        return ans;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, 2 + solve(i, nums[j] - nums[i], nums));
            }
        }
        return ans;
    }
};

// Memo
class Solution {
private:
    int solve(int idx, int prev, vector<int>& nums, vector<unordered_map<int,int>>& dp) {
        if (prev < 0) return 1; // only nums[idx] taken
        int diff = nums[idx] - nums[prev];

        if (dp[prev].count(diff)) return dp[prev][diff];

        // length of AP ending at nums[prev] with difference diff
        int best = 1; 
        for (int j = prev - 1; j >= 0; j--) {
            if (nums[prev] - nums[j] == diff) {
                best = max(best, 1 + solve(prev, j, nums, dp));
            }
        }
        return dp[prev][diff] = best;
    }

public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        vector<unordered_map<int,int>> dp(n);
        int ans = 2;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int len = 2;
                if (dp[j].count(diff)) {
                    len = dp[j][diff] + 1;
                } else {
                    len = 2; // start new subsequence
                }
                dp[i][diff] = len;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};


// Tab
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int ans = 0;
        unordered_map<int, int>dp[n + 1];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int count = 1;
                if (dp[j].count(diff)) count = dp[j][diff];
                dp[i][diff] = 1 + count;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};