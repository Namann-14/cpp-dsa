#include<iostream>
#include<sstream>
using namespace std;

string capital(string str){
    bool capitalize = true;
    for (int i = 0 ; i < str.size(); i++){
        if (isspace(str[i])){
            capitalize = true;
        }else if (capitalize &&  isalpha(str[i])){
            str[i] = toupper(str[i]);
            capitalize = false;
        }
    }
    return str;
}


int main(){
    string Name;
    getline(cin, Name);

    // stringstream ss(Name);
    // string word;
    // while(ss >> word){
    //     cout << word << endl;
    // }
    cout << capital(Name);
    return 0;
}