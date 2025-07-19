#include<iostream>
using namespace std;

bool isValidBugId(string bugId){
    for (char ch : bugId){
        if (!isalnum(ch)){
            return false;
        }
    }
    return true;
}

void validateSeverity(int severity){
    if (severity < 1 || severity > 10){
        throw out_of_range("Invalid Severity: " + to_string(severity));
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        string bugId;
        int severity;
        cin>> bugId >> severity;
        try{
            if (!isValidBugId(bugId)){
                throw invalid_argument("Invalid Bug id: " + bugId);
            }
            validateSeverity(severity);
            cout << "Bug id: " << bugId << "Severity: " << severity << endl;
        }catch(const invalid_argument &e){
            cerr << "Error: " << e.what() << endl;
        }catch(const out_of_range &e){
            cerr << "Error: " << e.what() << endl;
        }
    }
    return 0;
}