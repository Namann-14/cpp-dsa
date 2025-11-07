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
    
    string vowels = "AEIOUYaeiouy";
    string result = "";
    
    for (char c : s) {
        if (vowels.find(c) == string::npos) {
            result += '.';
            result += tolower(c);
        }
    }
    
    cout << result << endl;
    
    return 0;
}