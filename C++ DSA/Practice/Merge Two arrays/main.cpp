#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortArray(int arr[], int n){
    // INSERTION SORT
    for (int i = 1; i < n; i++ ){
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void mergeArray(int arr1[], int n,  int arr2[], int m, vector<int> &finalArray){
    int i = 0, j = 0;
    while(i < n && j < m){
        if (arr1[i] < arr2[j]){
            finalArray.push_back(arr1[i++]);
        }else{
            finalArray.push_back(arr2[j++]);
        }
    }
    while (i<n){
        finalArray.push_back(arr1[i++]);
    }
    while (j<m){
        finalArray.push_back(arr2[j++]);
    }
}

void printArray(vector<int>finalArray){
    for (int i = 0; i < finalArray.size(); i++){
        cout << finalArray[i] << " ";
    }
}

int main(){
    int arr1[] = {0,214,1,4,5,21,6,375,11,75,9};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {2525,235,6,4,278,211,1,8466,5132,8,74,21,684,5,64,51,635,21,3};
    int m = sizeof(arr2)/sizeof(arr2[0]);

    sortArray(arr1, n);
    sortArray(arr2, m);

    vector<int>finalArray;

    mergeArray(arr1, n, arr2, m, finalArray);
    printArray(finalArray);

    return 0;
}