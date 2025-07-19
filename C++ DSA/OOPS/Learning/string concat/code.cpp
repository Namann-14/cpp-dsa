#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    stringstream ss(str);
    string word;
    vector<string>ans;
    while(ss>>word){
        ans.push_back(word);
    }
    cout << ans.back().size();
    return 0;
}