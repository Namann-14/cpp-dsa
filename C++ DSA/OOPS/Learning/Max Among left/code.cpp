#include <iostream>
#include <vector>
using namespace std;

vector<int> maxLeft(vector<int>arr){
    int max = arr[0];
    vector<int>ans;
    for (int i = 1 ; i < arr.size(); i++){
        if (arr[i]>max){
            max = arr[i];
            ans.push_back(i);
        }
    }
    return ans;
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;  // Read the size of the array

    vector<int> arr(n);  // Declare a vector of size n

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Read each element of the array
    }

    // Output the array to verify input
    vector ans = maxLeft(arr);
    cout << "The array is: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
