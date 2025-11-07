#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

void solve() {
    string s;
    cin >> s;
    
    int firstOne = -1;
    int lastOne = -1;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            if (firstOne == -1) {
                firstOne = i;
            }
            lastOne = i;
        }
    }
    
    if (firstOne == -1) {
        cout << 0 << endl;
        return;
    }
    
    int zerosToErase = 0;
    for (int i = firstOne; i <= lastOne; i++) {
        if (s[i] == '0') {
            zerosToErase++;
        }
    }
    
    cout << zerosToErase << endl;
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