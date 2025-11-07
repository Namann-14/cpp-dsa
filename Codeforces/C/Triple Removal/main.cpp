#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr) {
    int n = arr.size();
    
    // Count 0s and 1s
    int count0 = 0, count1 = 0;
    for (int x : arr) {
        if (x == 0) count0++;
        else count1++;
    }
    
    // Check if it's possible to empty the array
    if (count0 % 3 != 0 || count1 % 3 != 0) {
        return -1;
    }
    
    if (n == 0) return 0;
    
    // Use memoization with the current array state
    map<vector<int>, int> memo;
    
    function<int(vector<int>)> dp = [&](vector<int> current) -> int {
        if (current.empty()) return 0;
        
        if (memo.count(current)) return memo[current];
        
        int result = 1e9;
        
        // Try all possible triples
        for (int i = 0; i < current.size(); i++) {
            for (int j = i + 1; j < current.size(); j++) {
                for (int k = j + 1; k < current.size(); k++) {
                    if (current[i] == current[j] && current[j] == current[k]) {
                        // Can form a triple
                        int cost = min(k - j, j - i);
                        
                        // Create new array without these elements
                        vector<int> next;
                        for (int l = 0; l < current.size(); l++) {
                            if (l != i && l != j && l != k) {
                                next.push_back(current[l]);
                            }
                        }
                        
                        result = min(result, cost + dp(next));
                    }
                }
            }
        }
        
        return memo[current] = result;
    };
    
    return dp(arr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            l--; r--; // Convert to 0-based indexing
            
            vector<int> subarray(a.begin() + l, a.begin() + r + 1);
            cout << solve(subarray) << "\n";
        }
    }
    
    return 0;
}
