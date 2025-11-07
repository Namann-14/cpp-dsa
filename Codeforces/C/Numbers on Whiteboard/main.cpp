#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

void solve() {
    int n;
    cin >> n;
    
    cout << 2 << endl;
    
    int current = n;
    
    for (int i = n - 1; i >= 1; i--) {
        cout << i << " " << current << endl;
        current = (i + current + 1) / 2;
    }
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