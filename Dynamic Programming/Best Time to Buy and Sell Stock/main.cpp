// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int mini = nums[0];
        int profit = 0;
        for (int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - mini;
            profit = max(profit, diff);
            mini = min(mini, nums[i]);
        }
        return profit;
    }
};