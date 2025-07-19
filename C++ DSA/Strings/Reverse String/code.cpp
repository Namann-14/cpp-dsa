#include <iostream>
#include <string>
#include <vector>
using namespace std;

void revStr(string &word) {
    int left = 0;
    int right = word.size() - 1;
    while (left < right) { 
        swap(word[left++], word[right--]);
    }
}

int main() {
    string str;
    getline(cin, str);
    vector<string> ans;
    string word = "";

    for (int i = 0; i <= str.size(); i++) {
        if (i < str.size() && str[i] != ' ') {
            word.push_back(str[i]);
        } else {
            if (!word.empty()) { 
                revStr(word);
                ans.push_back(word);
                word = ""; 
            }
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
