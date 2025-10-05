#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    long long n, rK, cK, rD, cD;
    cin >> n >> rK >> cK >> rD >> cD;

    long long dr = rK - rD;
    long long dc = cK - cD;

    // Scenario 1: The Chase
    if (dr * dc > 0) {
        cout << max(abs(dr), abs(dc)) << endl;
    } 
    // Scenario 2: The Push
    else {
        long long max_survival_time = 0;
        
        // Check run to r=0 (top wall)
        if (rD > rK) {
            max_survival_time = max(max_survival_time, rK + abs(cK - cD));
        }
        // Check run to r=n (bottom wall)
        if (rD < rK) {
            max_survival_time = max(max_survival_time, (n - rK) + abs(cK - cD));
        }
        // Check run to c=0 (left wall)
        if (cD > cK) {
            max_survival_time = max(max_survival_time, cK + abs(rK - rD));
        }
        // Check run to c=n (right wall)
        if (cD < cK) {
            max_survival_time = max(max_survival_time, (n - cK) + abs(rK - rD));
        }
        
        cout << max_survival_time << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}