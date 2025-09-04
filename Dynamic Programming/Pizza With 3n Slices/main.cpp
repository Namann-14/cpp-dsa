// https://leetcode.com/problems/pizza-with-3n-slices/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int idx, int end, int k, vector<int>& slices) {
        if (idx > end || k == 0) return 0;
        // include
        int incl = slices[idx] + solve(idx + 2, end, k - 1, slices);
        // exclude
        int excl = 0 + solve(idx + 1, end, k, slices);
        return max(incl, excl);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int case1 = solve(0, n - 2, n/3, slices);
        int case2 = solve(1, n - 1, n/3, slices);
        return max(case1, case2);
    }
};

// Memo
class Solution {
private:
    int solve(int idx, int end, int k, vector<int>& slices, vector<vector<int>>& dp) {
        if (idx > end || k == 0) return 0;
        if (dp[idx][k] != -1) return dp[idx][k];

        int incl = slices[idx] + solve(idx + 2, end, k - 1, slices, dp);
        int excl = solve(idx + 1, end, k, slices, dp);

        return dp[idx][k] = max(incl, excl);
    }

    int maxSum(vector<int>& slices, int start, int end, int k) {
        int n = slices.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(start, end, k, slices, dp);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int case1 = maxSum(slices, 0, n - 2, n / 3);
        int case2 = maxSum(slices, 1, n - 1, n / 3);
        return max(case1, case2);
    }
};


// Tab
class Solution {
private:
    int maxSum(vector<int>& slices, int start, int end, int k) {
        int len = end - start + 1;
        vector<vector<int>> dp(len + 2, vector<int>(k + 1, 0));

        for (int idx = len - 1; idx >= 0; idx--) {
            for (int j = 1; j <= k; j++) {
                int incl = slices[start + idx] + dp[idx + 2][j - 1];
                int excl = dp[idx + 1][j];
                dp[idx][j] = max(incl, excl);
            }
        }
        return dp[0][k];
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int case1 = maxSum(slices, 0, n - 2, n / 3);
        int case2 = maxSum(slices, 1, n - 1, n / 3);
        return max(case1, case2);
    }
};

// SO
class Solution {
private:
    int maxSum(vector<int>& slices, int start, int end, int k) {
        int len = end - start + 1;
        vector<int> prev2(k + 1, 0), prev1(k + 1, 0), curr(k + 1, 0);

        for (int idx = len - 1; idx >= 0; idx--) {
            for (int j = 1; j <= k; j++) {
                int incl = slices[start + idx] + prev2[j - 1];
                int excl = prev1[j];
                curr[j] = max(incl, excl);
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return curr[k];
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int case1 = maxSum(slices, 0, n - 2, n / 3);
        int case2 = maxSum(slices, 1, n - 1, n / 3);
        return max(case1, case2);
    }
};
