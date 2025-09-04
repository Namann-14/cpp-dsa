// https://leetcode.com/problems/russian-doll-envelopes/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];                   
        });
        vector<int> ans;
        for (auto &num : nums) {
            int h = num[1];
            auto it = lower_bound(ans.begin(), ans.end(), h);
            if (it == ans.end()) ans.push_back(h);
            else *it = h;
        }
        return ans.size();
    }
};
