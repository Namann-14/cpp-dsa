#include<iostream>
using namespace std;

void toLowerCase(char str[], int n) {
    for (int i = 0; i < n; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';  // Convert uppercase to lowercase
        }
    }
}

int stringLength(const char str[]) {
    int count = 0;
    while (str[count] != '\0') {  // Count until null character
        count++;
    }
    return count;
}

int removeSpecialCharacters(char str[], int n) {
    int index = 0;
    for (int i = 0; i < n; i++) {
        // Keep only alphanumeric characters (letters and digits)
        if (isalnum(str[i])) {
            str[index++] = str[i];  // Move valid characters forward
        }
    }
    str[index] = '\0';  // Mark the new end of the string
    return index;  // Return the new length of the string after removing special characters
}

bool checkPalindrome(const char str[], int n) {
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        if (str[start] != str[end]) {
            return false;  // If characters don't match, it's not a palindrome
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    char str[100];
    cin.getline(str, 100);  // Read input string

    int n = stringLength(str);
    cout << "String before: " << str << endl;

    toLowerCase(str, n);  // Convert to lowercase
    n = removeSpecialCharacters(str, n);  // Remove spaces and update the length
    cout << "String after: " << str << endl;

    if (checkPalindrome(str, n)) {
        cout << "This string is a Palindrome" << endl;
    } else {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}
