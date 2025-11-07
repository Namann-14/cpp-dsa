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
    
    int totalPresses = 0;
    
    for (int i = 1; i <= n; i++) {
        totalPresses += (n - i + 1);
    }
    
    cout << totalPresses << endl;
    
    return 0;
}