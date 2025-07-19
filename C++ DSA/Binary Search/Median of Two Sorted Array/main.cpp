#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
        vector<int> nums1 = {1,3};
        vector<int> nums2 = {2};
        int i = 0, j = 0;
        for (int i = 0 ; i < nums2.size() ; i++){
            nums1.push_back(nums2[i]);
        }

        sort(nums1.begin(), nums1.end());

        for (int i = 0 ; i < nums1.size() ; i++){
            cout << nums1[i] << endl;
        }

        int s = 0;
        int e = nums1.size() - 1;
        int mid = s + (e-s)/2;
        cout << "mid is: " << mid;
    return 0;
}