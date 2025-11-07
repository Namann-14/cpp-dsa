#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

void solve() {
    // Your code here
}

int32_t main() {
    fastio;
    int n, k;
    cin >> n >> k;
    while (k--) {
        if (n % 10 != 0) {
            n--;
        } else {
            n /= 10;
        }
    }
    cout << n << endl;
    return 0;
}