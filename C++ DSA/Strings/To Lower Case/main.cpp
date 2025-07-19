#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string str;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        }
    }
    cout << str <<  endl;
    
    string str2;
    str2 = str;

    for (char &x:str2){
        x = tolower(x);
    }
    
    cout<< "using inbuilt function: " << str2 << endl;

    return 0;
}