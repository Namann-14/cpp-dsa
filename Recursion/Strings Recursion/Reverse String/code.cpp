#include<iostream>
using namespace std;

void Rev(string& str, int start, int end){
    if (start > end){
        return ;
    }
    swap(str[start],str[end]);
    start++;
    end--;
    return Rev(str, start, end);
}

int main(){
    string str;
    getline(cin,str);
    int start = 0;
    int end = str.length() - 1;
    Rev(str,start,end);
    cout << "Reverse of String is: " << str << endl;
    return 0;
}