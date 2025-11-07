#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int count = 0;
    while (n--) {
        string str;
        cin >> str;
        if (str == "Tetrahedron") count += 4;
        if (str == "Cube") count += 6;
        if (str == "Octahedron") count += 8;
        if (str == "Dodecahedron") count += 12;
        if (str == "Icosahedron") count += 20;
    }
    cout << count << endl;
    return 0;
}