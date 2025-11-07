#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

int32_t main() {
    fastio;
    string str;
    cin >> str;
    
    vector<int> nums;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '+') {
            nums.pb(str[i] - '0');
        }
    }
    
    sort(all(nums));
    
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << "+";
        }
    }
    cout << endl;
    
    return 0;
}