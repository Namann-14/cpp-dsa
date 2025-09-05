// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
#include <bits/stdc++.h>
using namespace std;

// Memo
class Solution {
private:
    int solve(int left, int right, vector<int>& arr, map<pair<int, int>, int>& mp, vector<vector<int>>& dp) {
        if (left == right) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            ans = min(ans, mp[{left, i}] * mp[{i + 1, right}] + solve(left, i, arr, mp, dp) + solve(i + 1, right, arr, mp, dp));
        }
        return dp[left][right] = ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int, int>, int>mp;
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++) {
            mp[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                mp[{i, j}] = max(arr[j], mp[{i, j - 1}]);
            }
        }
        return solve(0, n - 1, arr, mp, dp);
    }
};

// Tab