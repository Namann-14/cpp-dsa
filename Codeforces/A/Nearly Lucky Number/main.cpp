#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

void solve(int n) {
    string str = to_string(n);
    int count = 0;
    for (char ch : str) {
        if (ch == '4' || ch == '7') {
            count++;
        }
    }
    if (count == 4 || count == 7) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    solve(t);
    return 0;
}