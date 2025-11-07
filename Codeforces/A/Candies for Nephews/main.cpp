#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;
    
    while (test--) {
        int n;
        cin >> n;
        int ans = (3 - n % 3) % 3;        
        cout << ans << '\n';
    }
    return 0;
}