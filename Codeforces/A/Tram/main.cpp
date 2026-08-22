#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        sum -= a;
        sum += b;

        maxi = max(maxi, sum);
    }

    cout << maxi << endl;

}
