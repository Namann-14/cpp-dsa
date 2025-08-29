// https://leetcode.com/problems/fibonacci-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int n, vector<int>& dp) {
        if (n == 1 || n == 0) return n;
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
        return dp[n];
    }
public:
    int fib(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};