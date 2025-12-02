#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  const int mod = 1e5;
public:
  int minimumMultiplications(vector<int>& nums, int start, int end) {
    if (start == end) {
      return 0;
    }
    vector<int>dist(1e5, 1e9);
    queue<pair<int, int>>q;
    q.push({start, 0});
    dist[start] = 0;
    while (!q.empty()) {
      auto [node, step] = q.front();
      q.pop();

      for (auto it : nums) {
        int num = (1LL * it * node) % mod;
        if (step + 1 < dist[num]) {
          dist[num] = step + 1;
          if (num == end) return step + 1;
          q.push({num, step + 1});
        }
      }
    }
    return -1;
  }
};
