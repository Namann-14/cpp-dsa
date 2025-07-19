#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int>>&Mat){
    for (int i = 0 ; i < Mat.size(); i++){
        for (int j = i+1; j < Mat.size() ; j++){
            swap(Mat[i][j], Mat[j][i]);
        }
    }
    for (int i = 0 ; i < Mat.size(); i++){
        reverse(Mat[i].begin(), Mat[i].end());
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> Mat(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Mat[i][j];
        }
    }
    rotate(Mat);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << Mat[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
