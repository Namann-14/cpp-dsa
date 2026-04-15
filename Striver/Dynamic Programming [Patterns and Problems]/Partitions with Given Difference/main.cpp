#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPartitions(vector<int>& nums, int diff) {
        return solve(0, nums, diff)
    }
};