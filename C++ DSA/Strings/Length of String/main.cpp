#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin, str);

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        count++;
    }
    cout << count << endl;

    cout << str.size() << endl;
    return 0;
}