#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int toasts_from_drink = (k * l) / nl;
    int toasts_from_limes = c * d;
    int toasts_from_salt = p / np;

    int ans = min({toasts_from_drink, toasts_from_limes, toasts_from_salt}) / n;
    cout << ans << '\n';

    return 0;
}
