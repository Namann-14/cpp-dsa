// https://leetcode.com/problems/minimum-sideway-jumps/description/
#include <bits/stdc++.h>
using namespace std;


// Recursion
class Solution {
private:
    int solve(int row, int col, int n, vector<int>& nums) {
        if (col == n - 1) return 0;
        if (nums[col + 1] != row) {
            return solve(row, col + 1, n, nums);
        }
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++) {
            if (i != row && nums[col] != i) {
                ans = min(ans, 1 + solve(i, col, n, nums));
            }
        }
        return ans;
    }
public:
    int minSideJumps(vector<int>& nums) {
        int n = nums.size();
        return solve(2, 0, n, nums);
    }
};


// Memoization
class Solution {
public:
    int minSideJumps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));
        dp[1][n - 1] = dp[2][n - 1] = dp[3][n - 1] = 0;
        for (int col = n - 2; col >= 0; col--) {
            for (int row = 1; row <= 3; row++) {
                if (nums[col] != row) {  
                    dp[row][col] = dp[row][col + 1];
                }
            }
            for (int row = 1; row <= 3; row++) {
                if (nums[col] != row) {
                    for (int k = 1; k <= 3; k++) {
                        if (row != k && nums[col] != k) {
                            dp[row][col] = min(dp[row][col], 1 + dp[k][col]);
                        }
                    }
                }
            }
        }
        return dp[2][0];
    }
};

// Space Optimisation
class Solution {
public:
    int minSideJumps(vector<int>& nums) {
        int n = nums.size();

        vector<int> next(4, 1e9), curr(4, 1e9);

        // Base case: at the last position, no jumps needed
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        // Traverse from right to left
        for (int col = n - 2; col >= 0; col--) {
            for (int row = 1; row <= 3; row++) {
                if (nums[col] != row) {
                    curr[row] = next[row]; // move forward
                } else {
                    curr[row] = 1e9; // obstacle blocks lane
                }
            }

            // Handle side jumps
            for (int row = 1; row <= 3; row++) {
                if (nums[col] != row) {
                    for (int k = 1; k <= 3; k++) {
                        if (row != k && nums[col] != k) {
                            curr[row] = min(curr[row], 1 + curr[k]);
                        }
                    }
                }
            }

            next = curr; // shift for next iteration
        }

        // Frog starts at lane 2, position 0
        return next[2];
    }
};
