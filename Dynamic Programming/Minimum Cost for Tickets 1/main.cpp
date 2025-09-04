// https://leetcode.com/problems/minimum-cost-for-tickets/description/
#include <bits/stdc++.h>
using namespace std;

// Recursion
class Solution {
private:
    int solve(int idx, int n, vector<int>& days, vector<int>& costs) {
        if (idx >= n) return 0;

        // 1 day pass
        int day1 = solve(idx + 1, n, days, costs) + costs[0];

        // 7 day pass
        int i;
        for (i = idx; i < n && days[i] < days[idx] + 7; i++);
        int day7 = solve(i, n, days, costs) + costs[1];

        // 30 day pass
        for (i = idx; i < n && days[i] < days[idx] + 30; i++);
        int day30 = solve(i, n, days, costs) + costs[2];

        int ans = min(day1, min(day7, day30));
        return ans;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solve(0, n, days, costs);
    }
};

// Top down
class Solution {
private:
    int solve(int idx, int n, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];

        // 1 day pass
        int day1 = solve(idx + 1, n, days, costs, dp) + costs[0];

        // 7 day pass
        int i;
        for (i = idx; i < n && days[i] < days[idx] + 7; i++);
        int day7 = solve(i, n, days, costs, dp) + costs[1];

        // 30 day pass
        for (i = idx; i < n && days[i] < days[idx] + 30; i++);
        int day30 = solve(i, n, days, costs, dp) + costs[2];

        int ans = min(day1, min(day7, day30));
        dp[idx] = ans;
        return dp[idx];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n + 1, -1);
        return solve(0, n, days, costs, dp);
    }
};


// Bottom Up
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            int day1 = costs[0] + dp[idx + 1];

            // 7-day pass
            int i = idx;
            while (i < n && days[i] < days[idx] + 7) i++;
            int day7 = costs[1] + dp[i];

            // 30-day pass
            i = idx;
            while (i < n && days[i] < days[idx] + 30) i++;
            int day30 = costs[2] + dp[i];

            dp[idx] = min({day1, day7, day30});
        }

        return dp[0];
    }
};
