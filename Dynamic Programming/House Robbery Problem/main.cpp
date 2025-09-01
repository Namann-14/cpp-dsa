// https://leetcode.com/problems/house-robber-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int incl = prev2 + nums[i];
            int excl = prev1;

            int curr = max(incl, excl);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int>first(nums.begin() + 1, nums.end());
        vector<int>second(nums.begin(), nums.end() - 1);
        return max(solve(first), solve(second));
    }
};