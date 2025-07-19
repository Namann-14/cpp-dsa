#include<iostream>
using namespace std;

int main() {
    int binary = 101;
    int answer = 0, i = 0;
    
    // cout << "Enter the binary number: ";
    // cin >> binary;

    while (binary) {
        int digit = binary & 1; 
        answer = digit * (1 << i) + answer;  
        binary >>= 1;  
        i++;
    }

    cout << "The decimal equivalent is: " << answer << endl;
    return 0;
}
