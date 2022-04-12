#include <string>
#include <iostream>

using namespace std;

class Trie {
public:
    class Node {
    public:
        bool end;
        Node *next[26];
        Node(bool end_ = false) {
            end = end_;
            for (auto & i : next) i = nullptr;
        }
    };

    Node *root;

    Trie() {
        root = new Node(false);
    }

    void insert(string word) {
        Node *curr = root;
        for (char ch : word) {
            Node *next = curr->next[ch - 'a'];
            if (!next)
                curr->next[ch - 'a'] = new Node(false);
            curr = curr->next[ch - 'a'];
        }
        curr->end = true;
    }

    bool search(string word) {
        Node* curr = root;
        for (char ch : word) {
            curr = curr->next[ch - 'a'];
            if (!curr) return false;
        }
        return curr->end;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (char ch : prefix) {
            curr = curr->next[ch - 'a'];
            if (!curr) return false;
        }
        return true;
    }
};

int main() {
    Trie *trie = new Trie();
    trie->insert("apple");
    trie->search("apple");   // return True
    trie->search("app");     // return False
    trie->startsWith("app"); // return True
    trie->insert("app");
    trie->search("app");     // return True
    return 0;
}
