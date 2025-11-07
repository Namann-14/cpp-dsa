#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

void solve() {
    string str;
    cin >> str;
    
    set<char> s;
    for (char c : str) {
        s.insert(c);
    }
    
    int count = s.size();
    
    if (count % 2 == 1) {
        cout << "IGNORE HIM!" << endl;
    } else {
        cout << "CHAT WITH HER!" << endl;
    }
}

int32_t main() {
    fastio;
    int t = 1;
    while (t--) solve();
    return 0;
}