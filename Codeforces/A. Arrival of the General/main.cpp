#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int maxi = 0;
    for (int i = 1; i < n; i++) {
        if (h[i] > h[maxi]) {
            maxi = i;
        }
    }

    int mini = 0;
    for (int i = 1; i < n; i++) {
        if (h[i] <= h[mini]) {
            mini = i;
        }
    }

    int ans = maxi + (n - 1 - mini);
    if (maxi > mini) ans -= 1;

    cout << ans << '\n';
    return 0;
}
