/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3434/
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class node {
public:
    bool isend;
    node* children[26];
    
    node() {
        isend = false;
        for(int i = 0; i < 26; i++)
            this->children[i] = NULL;
    }
};

class StreamChecker {
    node* root = new node();
    vector<char> v;
public:
    void add(node* root, string& word)
    {
        int ind;
        for(int i = 0; i < word.size(); i++)
        {
            ind = word[i]-'a';
            if(!root->children[ind])
                root->children[ind] = new node();
            root = root->children[ind];
        }
        root->isend = true;
    }
    
    bool search(node* root, string& word)
    {
        if(root == NULL) return false;
        
        int ind;
        for(int i = 0; i < word.size(); i++)
        {
            ind = word[i]-'a';
            if(root->children[ind] == NULL) return false;
            root = root->children[ind];
        }
        
        return root->isend;
    }
    
    StreamChecker(vector<string>& words) {
        for(auto w: words) {
            reverse(w.begin(), w.end());
            add(this->root, w);
        }
    }
    
    bool query(char letter) {
        
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */