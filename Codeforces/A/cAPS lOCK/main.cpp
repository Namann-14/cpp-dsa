
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

int32_t main() {
    fastio;
    string s;
    cin >> s;
    
    int n = s.length();
    bool shouldChange = true;
    
    for (int i = 1; i < n; i++) {
        if (islower(s[i])) {
            shouldChange = false;
            break;
        }
    }
    
    if (shouldChange) {
        for (int i = 0; i < n; i++) {
            if (isupper(s[i])) {
                s[i] = tolower(s[i]);
            } else {
                s[i] = toupper(s[i]);
            }
        }
    }
    
    cout << s << endl;
    
    return 0;
}