#include <bits/stdc++.h>
using namespace std;

void solve(int n, int i) {
   if (n == 0) return;
   if (n % i == 0) {
      cout << i << endl;
      solve(n / i, i + 1);
   } else {
      solve(n, i + 1);
   }
}

int main() {
   int n;
   cin >> n;
   solve(n, 2);
   return 0;
}