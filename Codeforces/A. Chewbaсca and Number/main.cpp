#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    string num = to_string(n);

    for (int i = 0; i < num.size(); i++) {
        int digit = num[i] - '0';
        if (9 - digit < digit) {
            if (i == 0 && (9 - digit) == 0) continue;
            num[i] = (9 - digit) + '0';
        }
    }

    cout << num << '\n';
    return 0;
}
