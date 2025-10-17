#include <bits/stdc++.h>
using namespace std;

void solve(string str, int n, vector<string>& dp) {
    if (n == 0) {
        dp[n] = str;
        cout << str << endl;   
        return;
    }
    if (n < 0) {
        return;
    }
    if (dp[n] != "") {
        cout << dp[n] << endl;
        return;
    }
    solve(str + '1', n - 1, dp);
    solve(str + '2', n - 2, dp);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<string>dp(n + 1, "");
    solve("", n, dp);
    return 0;
}