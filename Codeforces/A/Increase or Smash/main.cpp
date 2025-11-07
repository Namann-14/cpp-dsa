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

        set<int> distinct;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            distinct.insert(x);
        }
        
        int result = 2 * distinct.size() - 1;
        cout << result << "\n";
    }
    return 0;
}