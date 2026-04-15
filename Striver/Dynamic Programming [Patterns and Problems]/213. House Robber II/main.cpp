#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int idx, vector<int>& nums) {
        if (idx == 0) return nums[0];
        if (idx < 0) return 0;
        int incl = solve(idx - 2, nums)  + nums[idx];
        int excl = solve(idx - 1, nums);
        return max(incl, excl);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>a(nums.begin() + 1, nums.end());
        vector<int>b(nums.begin(), nums.end() - 1);
        return max(solve(a.size() - 1, a), solve(b.size() - 1, b));
    }
};