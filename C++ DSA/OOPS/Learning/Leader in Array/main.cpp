#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> leader(vector<int> &arr) {
    vector<int> result;
    int n = arr.size();
    int maxRight = INT_MIN;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] >= maxRight) {
            result.push_back(arr[i]);
            maxRight = arr[i];
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        arr.push_back(v);
    }

    vector<int> result = leader(arr);

    cout << "Leaders in the array are:" << endl;
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
