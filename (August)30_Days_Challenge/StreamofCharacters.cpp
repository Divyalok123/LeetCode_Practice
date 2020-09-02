/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3434/
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

static int x = [](){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();

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
    int maxlength;
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
    
    StreamChecker(vector<string>& words) {
        maxlength = -1;
        int length;
        for(auto& w: words) {
            reverse(w.begin(), w.end());
            add(this->root, w);
            length = w.length();
            if(maxlength < length)
                maxlength = length;
        }
    }
    
    bool query(char letter) {
        v.insert(v.begin(), letter);        
        int ind;
        node* thisroot = this->root;
        for(int i = 0; i < maxlength && i < v.size(); i++)
        {
            ind = v[i]-'a';
            if(thisroot->isend) return true;
            if(thisroot->children[ind] == NULL) return false;
            thisroot = thisroot->children[ind];
        }
        
        return thisroot->isend;
    }
};