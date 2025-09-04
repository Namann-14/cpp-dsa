// https://leetcode.com/problems/minimum-cost-for-tickets/
#include <bits/stdc++.h>
using namespace std;

// Space Optimization 
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        queue<pair<int, int>> weekPass, monthPass;
        int cost = 0;

        for (int d : days) {
            // Remove expired passes
            while (!weekPass.empty() && weekPass.front().first < d) weekPass.pop();
            while (!monthPass.empty() && monthPass.front().first < d) monthPass.pop();

            // Add new passes starting today
            weekPass.push({d + 7 - 1, cost + costs[1]});   // covers [d, d+6]
            monthPass.push({d + 30 - 1, cost + costs[2]}); // covers [d, d+29]

            // 1-day pass
            int oneDay = cost + costs[0];

            // Min cost among options
            int sevenDay = weekPass.front().second;
            int thirtyDay = monthPass.front().second;

            cost = min({oneDay, sevenDay, thirtyDay});
        }

        return cost;
    }
};
