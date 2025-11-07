#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int ans = 0;

    while (n--) {
        string str;
        cin >> str;
        if (str == "++X" || str == "X++") {
            ans++;
        } else {
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}