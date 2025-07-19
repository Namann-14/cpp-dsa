#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
    // Base case
    if (n == 0 || n == 1){
        return true;
    }
    // Reccuronce Relation
    if (arr[0] > arr[1]){
        return false;
    }else{
        return isSorted(arr + 1, n - 1);
    }
}

int main(){
    int arr1[6] = {2, 4, 8, 9, 9, 15};
    int arr2[5] = {5, 8, 2, 9, 3};

    if (isSorted(arr2, 5)){
        cout << "Array is sorted" << endl;
    }else{
        cout << "Array not sorted";
    }

    return 0;
}