// https://leetcode.com/problems/flood-fill/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void solve(vector<vector<int>>& nums, int x, int y, int color, int data, int m, int n) {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (nums[x][y] != data) return;
        nums[x][y] = -1; 
        solve(nums, x - 1, y, color, data, m, n);
        solve(nums, x + 1, y, color, data, m, n);
        solve(nums, x, y - 1, color, data, m, n);
        solve(nums, x, y + 1, color, data, m, n);
        nums[x][y] = color;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& nums, int sr, int sc, int color) {
        int m = nums.size();
        int n = nums[0].size();
        int data = nums[sr][sc];
        if (data == color) return nums;
        solve(nums, sr, sc, color, data, m, n);
        return nums;
    }
};
