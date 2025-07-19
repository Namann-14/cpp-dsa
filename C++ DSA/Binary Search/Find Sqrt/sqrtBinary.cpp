#include <iostream>
using namespace std;
int squareRoot(int n){
    int s = 0;
    int e = n;
    int mid;
    int ans = -1;
    while (s <= e) {
        mid = s + (e - s) / 2;
        int square = mid * mid;
        
        if (square == n) {
            ans = mid;
            break;
        }
        if (square > n) {
            e = mid - 1;
        } else {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    cout << "Square root of " << n << " is " << squareRoot(n) << endl;
    return 0;
}
