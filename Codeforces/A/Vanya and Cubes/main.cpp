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
    
    int height = 0;
    int totalUsed = 0;
    int level = 1;
    
    while (true) {
        int cubesForLevel = (level * (level + 1)) / 2;
        
        if (totalUsed + cubesForLevel <= n) {
            totalUsed += cubesForLevel;
            height++;
            level++;
        } else {
            break;
        }
    }
    
    cout << height << endl;
    
    return 0;
}