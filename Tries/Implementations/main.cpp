#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:           
        char data;
        TrieNode* children[26];
        bool isTerminal;
    
    TrieNode(char ch) {
        this->data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        // Check if a node has no children
        bool hasNoChildren(TrieNode* node) {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) return false;
            }
            return true;
        }

        // Insertion into trie
        void insertWord(TrieNode* root, string word) {
            if (word.size() == 0) {
                root->isTerminal = true;
                return;
            }
            int idx = word[0] - 'a';
            TrieNode* child;
            if (root->children[idx]) {
                child = root->children[idx];
            } else {
                child = new TrieNode(word[0]);
                root->children[idx] = child;
            }
            insertWord(child, word.substr(1));
        }

        // Searching in Trie
        bool searchWord(TrieNode* root, string word) {
            if (word.size() == 0) {
                return root->isTerminal;
            }
            int idx = word[0] - 'a';
            TrieNode* child;
            if (root->children[idx]) {
                child = root->children[idx];
            } else {
                return false;
            }
            return searchWord(child, word.substr(1));
        }

        // Deletion in Trie
        bool deleteWord(TrieNode* root, string word) {
            // Base case: reached end of word
            if (word.size() == 0) {
                if (!root->isTerminal) return false; // Word not present
                root->isTerminal = false;            // Unmark terminal
                return hasNoChildren(root);          // Can delete if no children
            }

            int idx = word[0] - 'a';
            TrieNode* child = root->children[idx];
            if (child == nullptr) return false;      // Word not present

            // Recursive call for rest of the word
            bool shouldDeleteChild = deleteWord(child, word.substr(1));

            // If child can be deleted, free it
            if (shouldDeleteChild) {
                delete root->children[idx];
                root->children[idx] = nullptr;
                return !root->isTerminal && hasNoChildren(root);
            }

            return false;
        }

        // Wrappers for convenience
        void insert(string word) { insertWord(root, word); }
        bool search(string word) { return searchWord(root, word); }
        void _delete(string word) { deleteWord(root, word); }

        // Print all words in the Trie
        void printAllWords(TrieNode* node, string prefix) {
            if (node->isTerminal) {
                cout << prefix << endl;
            }
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    printAllWords(node->children[i], prefix + char('a' + i));
                }
            }
        }

        void printAllWords() {
            cout << "All words in Trie:" << endl;
            printAllWords(root, "");
        }
};

int main() {   
    Trie trie;
    
    cout << "=== Trie Implementation Demo ===" << endl;
    
    // Insert words
    cout << "\nInserting words: hello, world, help, her, hero" << endl;
    trie.insert("hello");
    trie.insert("world");
    trie.insert("help");
    trie.insert("her");
    trie.insert("hero");
    
    // Print all words
    trie.printAllWords();
    
    // Search words
    cout << "\n=== Search Operations ===" << endl;
    vector<string> searchWords = {"hello", "help", "her", "test", "wor"};
    for (string word : searchWords) {
        bool found = trie.search(word);
        cout << "Search '" << word << "': " << (found ? "Found" : "Not Found") << endl;
    }
    
    // Delete operations
    cout << "\n=== Delete Operations ===" << endl;
    cout << "Deleting 'help'..." << endl;
    trie._delete("help");
    
    cout << "Search 'help' after deletion: " << (trie.search("help") ? "Found" : "Not Found") << endl;
    cout << "Search 'hello' after deletion: " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    
    cout << "\nWords after deletion:" << endl;
    trie.printAllWords();
    
    return 0;
}
