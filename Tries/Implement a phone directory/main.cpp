// https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
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

    void print(TrieNode* curr, vector<string>& temp, string& prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (curr->children[i]) {
                prefix.push_back('a' + i);
                print(curr->children[i], temp, prefix);
                prefix.pop_back();
            }
        }
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        insertWord(root, word);
    }

    void solve(vector<vector<string>>& ans, string& s) {
        TrieNode* prev = root;
        string prefix = "";
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            prefix.push_back(ch);
            TrieNode* curr = prev->children[ch - 'a'];
            if (curr == nullptr) {
                // // No further matches ? push empty lists for remaining characters
                // while (i < s.size()) {
                //     ans.push_back({"0"});
                //     i++;
                // }
                // return;
                break;
            }
            vector<string> temp;
            print(curr, temp, prefix);
            ans.push_back(temp);
            prev = curr;
        }
    }
};
vector<vector<string>> phoneDirectory(vector<string>& words, string& s) {
    vector<vector<string>> ans;
    if (words.empty()) return ans;
    Trie* t = new Trie();
    for (string word : words) {
        t->insert(word);
    }
    t->solve(ans, s);
    return ans;
}

