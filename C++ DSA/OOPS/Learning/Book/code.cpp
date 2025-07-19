#include <iostream>
#include <string> // Include string for getline
using namespace std;

class Book {
    private:
        string title;
        int pages;

    public:
        Book(string t, int p) : title(t), pages(p) {}

        // Overloaded '>' operator
        bool operator>(Book &other) {
            return pages > other.pages;
        }
};

int main() {
    string title1, title2;
    int page1, page2;

    // Input for titles
    cout << "Enter title of Book 1: ";
    getline(cin, title1);
    cout << "Enter title of Book 2: ";
    getline(cin, title2);

    // Input for page counts
    cout << "Enter page count of Book 1: ";
    cin >> page1;
    cout << "Enter page count of Book 2: ";
    cin >> page2;

    // Create Book objects
    Book b1(title1, page1);
    Book b2(title2, page2);

    // Compare and output result
    if (b1 > b2) {
        cout << "Book 1 has more pages." << endl;
    } else {
        cout << "Book 2 has more pages." << endl;
    }

    return 0;
}
