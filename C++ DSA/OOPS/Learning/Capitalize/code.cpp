#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string str;
    getline(cin, str);  // Read the whole line
    stringstream ss(str);
    string word;
    vector<string> ans;

    // Split the input string into words
    while(ss >> word) {
        ans.push_back(word);
    }

    // Process each word based on its length
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].size() < 2) {
            // Convert to lowercase if the word is less than 2 characters
            for (char &ch : ans[i]) {
                ch = tolower(ch);
            }
        } else {
            // Capitalize the first letter and lowercase the rest of the letters
            ans[i][0] = toupper(ans[i][0]);
            for (int j = 1; j < ans[i].size(); j++) {
                ans[i][j] = tolower(ans[i][j]);
            }
        }
    }

    // Output the modified words
    for (const string &word : ans) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
