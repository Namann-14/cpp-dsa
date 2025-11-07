#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

void solve() {
    string x;
    cin >> x;
    
    int digit = x[0] - '0';
    int length = x.length();
    
    int totalPresses = 0;
    
    totalPresses += (digit - 1) * 10;
    
    for (int i = 1; i <= length; i++) {
        totalPresses += i;
    }
    
    cout << totalPresses << endl;
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}