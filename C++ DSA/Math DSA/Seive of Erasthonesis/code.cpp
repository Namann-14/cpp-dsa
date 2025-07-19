#include <iostream>
#include <vector>
using namespace std;

vector<int> primes(int n) {
    vector<int> sieve(n + 1, 1); 
    vector<int> ans;
    sieve[0] = sieve[1] = 0; 
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i] == 1) { 
            for (int j = i * i; j <= n; j += i) { 
                sieve[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++) { 
        if (sieve[i] == 1) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    // Find all prime numbers between 0 and n
    int n;
    cin >> n;
    vector<int> ans = primes(n);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
