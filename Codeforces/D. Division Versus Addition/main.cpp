#include <bits/stdc++.h>
using namespace std;

// Function to calculate how many divisions are needed to make x become 1
int divisions_needed(long long x) {
    int count = 0;
    while (x > 1) {
        x /= 2;
        count++;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--; // Convert to 0-indexed
            
            // Calculate divisions needed for each element initially
            vector<int> divs;
            for (int i = l; i <= r; i++) {
                divs.push_back(divisions_needed(a[i]));
            }
            
            // The key insight: Rekkles will always target the element that 
            // currently requires the most divisions to become 1
            // This creates an optimal strategy for both players
            
            // Total moves by Poby
            long long total_moves = 0;
            
            // Priority queue to simulate the game state
            priority_queue<int> pq;
            for (int d : divs) {
                if (d > 0) pq.push(d);
            }
            
            // Simulate optimal play
            while (!pq.empty()) {
                // Poby's turn - he reduces the element with most divisions needed
                int max_divs = pq.top();
                pq.pop();
                total_moves++;
                
                // After division, this element needs one less division
                if (max_divs > 1) {
                    pq.push(max_divs - 1);
                }
                
                // If game is over, break
                if (pq.empty()) break;
                
                // Rekkles's turn - he increases the element with most divisions needed
                max_divs = pq.top();
                pq.pop();
                
                // After adding 1, the element needs one more division
                pq.push(max_divs + 1);
            }
            
            cout << total_moves << "\n";
        }
    }
    
    return 0;
}