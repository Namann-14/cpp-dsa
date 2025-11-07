#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

int32_t main() {
    fastio;
    string str;
    cin >> str;
    if (!str.empty()) {
        str[0] = toupper(str[0]);
    }
    cout << str << endl;
    return 0;
}