#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int grid[5][5];
    int row = -1, col = -1;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                row = i;
                col = j;
            }
        }
    }

    int ans = abs(2 - row) + abs(2 - col);
    cout << ans << '\n';

    return 0;
}
