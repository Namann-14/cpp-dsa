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
    string t;
    cin >> t;
    
    string result = "";
    int i = 0;
    int count = 1;
        
    while (i < n) {
        result += t[i];
        i += count;
        count++;
    }
    
    cout << result << endl;
    
    return 0;
}