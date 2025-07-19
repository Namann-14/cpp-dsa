#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);  // Read the entire input line
    
    for (int i = 0; i < str.size() - 1; i++) {
        int diff = str[i + 1] - str[i];
        cout << str[i] << diff;  // Print character and its difference
    }

    if (!str.empty()) {
        cout << str.back();  // Print the last character
    }

    return 0;
}
