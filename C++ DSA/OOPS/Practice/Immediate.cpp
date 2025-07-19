#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int key;
    cin >> key;

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        arr.push_back(v);
    }

    sort(arr.begin(), arr.end());
    int size = arr.size();
    for (int i = 0 ; i < size; i++){
        if ( key == arr[size] )
    }
    return 0;
}