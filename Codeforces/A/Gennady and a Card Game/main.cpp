#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define pb push_back

int32_t main() {
    fastio;
    string tableCard;
    cin >> tableCard;
    
    char tableRank = tableCard[0];
    char tableSuit = tableCard[1];
    
    bool canPlay = false;
    
    for (int i = 0; i < 5; i++) {
        string handCard;
        cin >> handCard;
        
        char handRank = handCard[0];
        char handSuit = handCard[1];
        
        if (handRank == tableRank || handSuit == tableSuit) {
            canPlay = true;
        }
    }
    
    if (canPlay) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}