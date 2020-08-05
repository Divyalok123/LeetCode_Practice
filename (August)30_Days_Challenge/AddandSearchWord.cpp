/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
 */

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class trieNode {
public:
    bool isTerm;
    trieNode* children[26];
    trieNode() {
        this->isTerm = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class WordDictionary {
    trieNode* root = new trieNode();
    bool search(string word, trieNode* node) {
        if (word.size() == 0)
            return node && node->isTerm;

        if (!node)
            return false;

        for (int i = 0; i < word.size(); i++) {
            if (!node) break;
            if (word[i] != '.') {
                node = node->children[word[i]-'a'];
            }
            else {
                trieNode* temp = node;
                for (int k = 0; k < 26; k++) {
                    node = temp->children[k];
                    if (search(word.substr(i+1), node))
                        return true;
                }
            }
        }
        return node && node->isTerm;
    }

public:
    WordDictionary() {}

    void addWord(string word) {

        trieNode* node = root;
        for (char c: word) {
            if (node->children[c-'a'] == NULL) {
                node->children[c-'a'] = new trieNode();
            }
            node = node->children[c-'a'];
        }
        node->isTerm = true;
    }

    bool search(string word) {
        return search(word, root);
    }
};