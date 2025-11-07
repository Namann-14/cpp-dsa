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
    vector<int> giver(n + 1);
    
    for (int i = 1; i <= n; i++) {
        int receiver;
        cin >> receiver;
        giver[receiver] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << giver[i];
        if (i < n) cout << " ";
    }
    cout << endl;
}

int32_t main() {
    fastio;
    int t = 1;
    while (t--) solve();
    return 0;
}