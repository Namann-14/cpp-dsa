#include<iostream>
using namespace std;

int main() {
    string str;
    getline(cin, str); 

    cout << "size of string before: " << str.size() << endl; 

    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            swap(str[i], str[count]); 
            count++;
        }
    }

    str[count] = '\0'; 
    cout << "size of string after: " << str.size() << endl; 
    cout << str; 
    return 0;
}
