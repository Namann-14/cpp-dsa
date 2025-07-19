#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int arr[26] = {0};
    for (int i = 0 ; i < str.size(); i++){
        int num = str[i] - 'a';
        arr[num]++;
    }
    int maxi = -1, ans = -1;
    for (int i = 0; i < 26; i++)
    {
        if (maxi<arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    char ch = ans + 'a';
    cout << "Max occurrence is of " << ch << maxi << "times";
    // for(int i = 0 ; i<26; i++){
    //     cout << arr[i] << " ";
    // }
    return 0;
}