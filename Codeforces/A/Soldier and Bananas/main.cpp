#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

void solve() {
    int k, n, w;
    cin >> k >> n >> w;

    int totalCost = k * w * (w + 1) / 2;
    int borrow = max(0LL, totalCost - n);
    
    cout << borrow << endl;
}

int32_t main() {
    fastio;
    int t = 1;
    while (t--) solve();
    return 0;
}