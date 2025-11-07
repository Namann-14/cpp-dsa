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
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int maxLen = 1;
    int currentLen = 1;
    
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            currentLen++;
            maxLen = max(maxLen, currentLen);
        } else {
            currentLen = 1;
        }
    }
    
    cout << maxLen << endl;
    
    return 0;
}