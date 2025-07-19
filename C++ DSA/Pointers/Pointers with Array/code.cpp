#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5};

    /*
    cout << arr << endl; 
    cout << *arr << endl; 
    cout << &arr << endl; 
    cout << arr[0] << endl; 
    cout << &arr[0] << endl; 
    cout << *(arr + 1) << endl;
    cout << 4[arr] << endl;
    cout << *(arr + 4) << endl;
    */ 

    /*
    int temp[10];
    cout << sizeof(temp) << endl;
    int *ptr = temp;
    cout << sizeof(ptr) << endl;
    cout << sizeof(*ptr) << endl;
    */

   // Symbol table cannot be changed
   int nums[] = {1,2,3,4,5,6,7,8,9,10};

   // ERROR
   // nums = nums + 1;

   int *p = &nums[0];
   cout << (nums + 1)  << endl;

   p = p + 1;
   cout << p << endl;

    return 0;
}