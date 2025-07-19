#include<iostream>
using namespace std;

string missingPangram(string str){
    int arr[26] = {0};
    for (int i = 0 ; i < str.size() ; i++){
        arr[str[i]-'a']++;
    }
    string ans = "";
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == 0)    
        {
            ans += 'a' + i;
        }
        
    }
    return ans; 
}

int main(){
    string str;
    getline(cin, str);
    cout << missingPangram(str);
    return 0;
}