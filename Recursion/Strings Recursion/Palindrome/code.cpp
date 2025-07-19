#include<iostream>
using namespace std;

bool Palindrome(string str, int start, int end){
    if (start > end){
        return 1;
    }
    if (str[start] != str[end]){
        return 0;
    }
    start++;
    end--;
    return Palindrome(str,start, end);
}

int main(){
    string str;
    getline(cin, str);

    int start = 0;
    int end = str.length() - 1;
    cout << "String is Palindrome " << Palindrome(str, start, end);
    return 0;
}