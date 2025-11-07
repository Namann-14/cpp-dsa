#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    
    int operations = 0;
    
    while (a <= n && b <= n) {
        if (a < b) {
            a += b;
        } else {
            b += a;
        }
        operations++;
    }
    
    cout << operations << endl;
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