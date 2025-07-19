#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    stringstream ss(str);
    string word;
    vector<string>sentence;
    while(ss>>word){
        sentence.push_back(word);
    }
    for (string i : sentence){
        swap(i.front(), i.back());
        cout << i << " ";
    }
    return 0;
}