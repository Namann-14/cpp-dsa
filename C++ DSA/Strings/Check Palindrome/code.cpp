#include <iostream>
#include <string>
using namespace std;

void toLower(string &str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

void removeSpecialCharacter(string &str) {
    int idx = 0;
    for (int i = 0; i < str.size(); i++) {
        if (isalnum(str[i])) {
            str[idx++] = str[i]; // Copy valid character to the correct position
        }
    }
    str.resize(idx); // Resize string to remove extra characters
}

bool checkPalindrome(string str) {
    toLower(str);
    removeSpecialCharacter(str);
    int left = 0, right = str.size() - 1;
    while (left <= right) {
        if (str[left++] != str[right--]) {
            return false; // Early return on mismatch
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    cout << (checkPalindrome(str) ? "Palindrome" : "Not a Palindrome") << endl;
    return 0;
}
