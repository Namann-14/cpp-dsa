#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for (int i = 0 ; i < 10 ; i++){
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);
    }

    cout << "Max: " << maxVal << endl;
    cout << "Min: " << minVal << endl;

    return 0;
}