// https://leetcode.com/problems/longest-common-prefix/

// APPROACH 1: 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            bool match = true;
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].size() < i || ch != strs[j][i]) {
                    match = false;
                    break;
                }
            }
            if (match == false) {
                break;
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};


// APPROACH 2: TRIES
class Solution {
private:
    class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char data) {
            this->data = data;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isTerminal = false;
        }
    };
    
    class Trie {
    private:
        TrieNode* root;
        string ans = "";
        void insertWord(TrieNode* root, string word) {
            if (word.empty()) {
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

        void prefix(TrieNode* root) {
            if (!root)
                return;
            if (root->isTerminal)
                return;
            int count = 0;
            int idx = -1;
            for (int i = 0; i < 26; i++) {
                if (root->children[i]) {
                    count++;
                    idx = i;
                }
            }
            if (count != 1)
                return;

            ans += root->children[idx]->data;

            prefix(root->children[idx]);
        }

    public:
        Trie() { root = new TrieNode('\0'); }
        void insert(string word) { insertWord(root, word); }

        string solve() {
            prefix(root);
            return ans;
        }
    };

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        Trie* t = new Trie();
        for (string word : strs) {
            t->insert(word);
        }
        return t->solve();
    }
};