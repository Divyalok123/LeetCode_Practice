// Implement a trie with insert, search, and startsWith methods.

// Example:

// Trie trie = new Trie();

// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
// Note:

// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.

#include <iostream>
#include <string>
using namespace std;

class TrieNode {   
public:
    char data;
    TrieNode** arr;
    bool isTerminal;
    
    TrieNode(char data)
    {
        this->data = data;
        arr = new TrieNode*[26];
        for(int i = 0; i < 26; i++)
        {
            arr[i] = NULL;
        }
        
        isTerminal = false;
    }
};

class Trie {
    
    TrieNode* root;
    
    void insert(TrieNode* root, string word)
    {
        if(word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        
        
        TrieNode* child;
        if(root->arr[word[0] - 'a'] != NULL)
        {
            child = root->arr[word[0] - 'a'];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->arr[word[0]-'a'] = child;
        }
        
        insert(child, word.substr(1));
    }
    
    bool search(TrieNode* root, string word)
    {
        if(word.size() == 0)
        {
            return root->isTerminal;
        }
        
        TrieNode* child = root->arr[word[0]-'a'];
        if(child == NULL) return false;
        return search(child, word.substr(1));
    }
    
    bool startsWith(TrieNode* root, string word)
    {
        if(word.size() == 0)
            return true;
        
        TrieNode* child = root->arr[word[0]-'a'];
        
        if(child == NULL) return false;
        return startsWith(child, word.substr(1));
        
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insert(root, word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search(root, word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWith(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */