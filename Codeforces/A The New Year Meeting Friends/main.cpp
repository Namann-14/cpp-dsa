#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int>nums(3);
    for (int i = 0; i < 3; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int ans = (nums[2] - nums[1]) + (nums[1] - nums[0]);

    cout << ans << '\n';    

    return 0;
}