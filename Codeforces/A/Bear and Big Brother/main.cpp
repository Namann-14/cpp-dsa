#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

void solve() {
    int a, b;
    cin >> a >> b;
    
    int years = 0;
    
    while (a <= b) {
        a *= 3;
        b *= 2; 
        years++;
    }
    
    cout << years << endl;
}

int32_t main() {
    fastio;
    int t = 1;
    while (t--) solve();
    return 0;
}