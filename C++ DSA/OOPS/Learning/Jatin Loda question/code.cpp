#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void hacked(string str1, char ch, string str2) {
    vector<string> ans;
    stringstream ss(str1);
    string word;

    while (getline(ss, word, ch)) {
        ans.push_back(word);
    }

    for (string i : ans) {
        if (i == str2) {
            cout << "HACKED " << i << endl;
            break;
        }else{
            cout << "NOT HACKED";
        }
    }
}

int main() {
    string str1, str2;

    cout << "Enter the main string: ";
    getline(cin, str1);
    cout << "Enter the word to check: ";
    getline(cin, str2);

    char ch = '#';
    hacked(str1,ch,str2);
    return 0;
}
