#include <iostream>
using namespace std;
int main() {
    int m;
    cin >> m;
    int arr[m];
    for (int i = 0; i < m; i++) {
    cin >> arr[i];
}
int largest = 0; 
bool found = false;
for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[j] == -arr[i]) {
                found = true; 
            if (arr[i] > largest) {
                largest = arr[i];
            }
            break; 
        }
        }
    }
if (found) {
    cout << largest << endl;
    } else {
    cout << -1 << endl;
    }
    return 0;
}