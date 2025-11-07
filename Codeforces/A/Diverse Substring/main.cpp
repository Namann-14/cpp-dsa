#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

int32_t main() {
    fastio;
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            cout << "YES" << endl;
            cout << s[i] << s[i + 1] << endl;
            return 0;
        }
    }
    
    cout << "NO" << endl;
    
    return 0;
}