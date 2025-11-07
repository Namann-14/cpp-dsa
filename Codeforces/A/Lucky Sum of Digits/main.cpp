
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
    
    int bestFours = -1, bestSevens = -1;
    
    for (int sevens = 0; sevens * 7 <= n; sevens++) {
        int remaining = n - sevens * 7;
        if (remaining % 4 == 0) {
            int fours = remaining / 4;
            if (bestFours == -1 || fours + sevens < bestFours + bestSevens) {
                bestFours = fours;
                bestSevens = sevens;
            }
        }
    }
    
    if (bestFours == -1) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < bestFours; i++) {
            cout << 4;
        }
        for (int i = 0; i < bestSevens; i++) {
            cout << 7;
        }
        cout << endl;
    }
    
    return 0;
}