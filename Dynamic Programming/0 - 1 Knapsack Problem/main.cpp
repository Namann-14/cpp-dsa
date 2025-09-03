// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
#include <bits/stdc++.h>
using namespace std;

// Recursion
class Solution {
    private:
        int solve(int idx, int n, int w, vector<int>& val, vector<int>& wt) {
            if (idx == 0) {
                if (wt[idx] <= w) {
                    return val[idx];
                } else {
                    return 0;
                }
            }
            // incl
            int incl = 0;
            if (wt[idx] <= w) {
                incl = solve(idx - 1, n, w - wt[idx], val, wt) + val[idx];
            }
            int excl = solve(idx - 1, n, w, val, wt) + 0;

            return max(incl, excl);
        }
    public:
        int knapsack(int w, vector<int> &val, vector<int> &wt) {
            int n = val.size();
            return solve(n- 1, n, w, val, wt);
        }
};

// Top Down Memo
class Solution {
    private:
        int solve(int idx, int n, int w, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
            if (idx == 0) {
                if (wt[idx] <= w) {
                    return val[idx];
                } else {
                    return 0;
                }
            }
            if (dp[idx][w] != -1) return dp[idx][w];
            // incl
            int incl = 0;
            if (wt[idx] <= w) {
                incl = solve(idx - 1, n, w - wt[idx], val, wt, dp) + val[idx];
            }
            int excl = solve(idx - 1, n, w, val, wt, dp) + 0;

            dp[idx][w] = max(incl, excl);
            return dp[idx][w];
        }
    public:
        int knapsack(int w, vector<int> &val, vector<int> &wt) {
            int n = val.size();
            // 2d dp 
            // row -> index (n)
            // col -> max weight (w)
            vector<vector<int>>dp(n, vector<int>(w + 1, -1));
            return solve(n- 1, n, w, val, wt, dp);
        }
};

// Bottom Up - Complete 2D DP
class Solution {
    private:
        int solve(int w, vector<int>& val, vector<int>& wt) {
            int n = val.size();
            vector<vector<int>>dp(n, vector<int>(w + 1, 0));
            
            // Base case: fill first row
            for (int weight = 0; weight <= w; weight++) {
                if (wt[0] <= weight) {
                    dp[0][weight] = val[0];
                } else {
                    dp[0][weight] = 0;
                }
            }
            
            // Fill the DP table
            for (int i = 1; i < n; i++) {
                for (int weight = 0; weight <= w; weight++) {
                    // Exclude current item
                    int excl = dp[i-1][weight];
                    
                    // Include current item (if possible)
                    int incl = 0;
                    if (wt[i] <= weight) {
                        incl = dp[i-1][weight - wt[i]] + val[i];
                    }
                    
                    dp[i][weight] = max(incl, excl);
                }
            }
            
            return dp[n-1][w];
        }
    public:
        int knapsack(int w, vector<int> &val, vector<int> &wt) {
            return solve(w, val, wt);
        }
};

// Space Optimized - Using 2 Arrays (Previous and Current Row)
class Solution {
    private:
        int solve(int w, vector<int>& val, vector<int>& wt) {
            int n = val.size();
            vector<int> prev(w + 1, 0);
            vector<int> curr(w + 1, 0);
            
            // Base case: fill first row
            for (int weight = 0; weight <= w; weight++) {
                if (wt[0] <= weight) {
                    prev[weight] = val[0];
                } else {
                    prev[weight] = 0;
                }
            }
            
            // Fill using only two arrays
            for (int i = 1; i < n; i++) {
                for (int weight = 0; weight <= w; weight++) {
                    // Exclude current item
                    int excl = prev[weight];
                    
                    // Include current item (if possible)
                    int incl = 0;
                    if (wt[i] <= weight) {
                        incl = prev[weight - wt[i]] + val[i];
                    }
                    
                    curr[weight] = max(incl, excl);
                }
                // Swap arrays for next iteration
                prev = curr;
            }
            
            return prev[w];
        }
    public:
        int knapsack(int w, vector<int> &val, vector<int> &wt) {
            return solve(w, val, wt);
        }
};

// Space Optimized - Using Single 1D Array
class Solution {
    private:
        int solve(int w, vector<int>& val, vector<int>& wt) {
            int n = val.size();
            vector<int> dp(w + 1, 0);
            
            // Base case: fill for first item
            for (int weight = 0; weight <= w; weight++) {
                if (wt[0] <= weight) {
                    dp[weight] = val[0];
                } else {
                    dp[weight] = 0;
                }
            }
            
            // Process remaining items
            for (int i = 1; i < n; i++) {
                // Traverse from right to left to avoid using updated values
                for (int weight = w; weight >= 0; weight--) {
                    // Include current item (if possible)
                    int incl = 0;
                    if (wt[i] <= weight) {
                        incl = dp[weight - wt[i]] + val[i];
                    }
                    
                    // dp[weight] already contains exclude value
                    dp[weight] = max(incl, dp[weight]);
                }
            }
            
            return dp[w];
        }
    public:
        int knapsack(int w, vector<int> &val, vector<int> &wt) {
            return solve(w, val, wt);
        }
};