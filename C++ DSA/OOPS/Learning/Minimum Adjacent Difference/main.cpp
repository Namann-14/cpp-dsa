#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr; 

    for (int i = 0; i < n; i++) {
        int val; 
        cin >> val;
        arr.push_back(val); 
    }

    int minDiff = INT_MAX;
    int diff = 0;
    for(int i = 1 ; i < arr.size(); i++){
        diff = abs(arr[i] - arr[i-1]);
        if (diff < minDiff){
            minDiff = diff;
        }
    }
    diff = abs(arr[arr.size() - 1] - arr[0]);
    if (diff < minDiff){
        minDiff = diff;
    }

    cout << "Minimum difference is: " << minDiff;

    return 0;
}
