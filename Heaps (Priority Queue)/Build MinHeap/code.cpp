// https://www.naukri.com/code360/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
void solve(vector<int>& arr, int n, int i) {
    int smallest = i;
    int leftIdx = 2 * i + 1;
    int rightIdx = 2 * i + 2;
    if (leftIdx < n && arr[leftIdx] < arr[smallest]) {
        smallest = leftIdx;
    }
    if (rightIdx < n && arr[rightIdx] < arr[smallest]) {
        smallest = rightIdx;
    }
    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        solve(arr, n, smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr){
    int n = arr.size();
    for (int i = n/2 - 1; i >= 0; i--) {
        solve(arr, n, i);
    }
    return arr;
}


