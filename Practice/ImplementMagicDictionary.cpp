/*
https://leetcode.com/problems/zigzag-conversion/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Solution 5 (trie based solution)
class node {
public:
    node* arr[26] = {};
    bool isend;
    
    node() {
        isend = false;
    }
};

class MagicDictionary {
    node* mainroot;
    
    bool search(const string& s, int i, bool check, node* root) {
        if(i == s.size()) 
            return root->isend && check;
        
        if(!root) return 0;
        
        if(root->arr[s[i]-'a'] && search(s, i+1, check, root->arr[s[i]-'a']))
            return true;
        
        if(!check) {
            for(int j = 0; j < 26; j++) {
                if(s[i] != 'a'+j && root->arr[j] && search(s, i+1, 1, root->arr[j]))
                        return true;
            }
        }
        return 0;
    }
    
public:
    MagicDictionary() {
        mainroot = new node();
    }
    
    void buildDict(const vector<string>& dictionary) {
        for(const string& ref: dictionary) {
            node* temp = mainroot;
            for(const auto& c: ref) {
                auto& t = temp->arr[c-'a']; 
                if(t == NULL)
                    t = new node();
                temp = t;
            }
            temp->isend = true;
        }
    }
    
    bool search(const string& sw) {
        return search(sw, 0, 0, mainroot);
    }
};

// Solution 4 (Generalised neighbors solution - Solution 3 performed better :( )
class MagicDictionary {
    unordered_map<string, int> mapp;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto& s: dictionary) {
            mapp[s]++;
            for(int i = 0; i < s.size(); i++)
            {
                char c = s[i];
                s[i] = '*';
                mapp[s]++;
                s[i] = c;
            }
        } 
    }
    
    bool search(string sw) {
        int c = 1;
        if(mapp[sw]) c = 2;
        
        for(int i = 0; i < sw.size(); i++)
        {
            char ch = sw[i];
            sw[i] = '*';
            if(mapp[sw] >= c) 
                return 1;
            sw[i] = ch;
        }
        return 0;
    }
};

// Solution 3 (word to word comparison - Improved RT to great extent but depends on testcases 
//            i.e. if all the strings have same size in all testcases it can perform worse than sol 2)

class MagicDictionary {
    unordered_map<int, unordered_set<string>> mapp;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto& s: dictionary) {
            int n = s.size();
            mapp[n].insert(s);
        } 
    }
    
    bool search(string sw) {
        int n = sw.size();
        const auto& sett = mapp[n];
        for(const string& i: sett) {
            int mis = 0;
            for(int j = 0; j < n; j++) {
                if(sw[j] != i[j])
                    mis++;
            }
            
            if(mis == 1) return 1;
        }
        
        return 0;
    }
};

// Solution 2 (Little improvement over sol 1)
class MagicDictionary {
    unordered_map<int, unordered_set<string>> mapp;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto& s: dictionary) {
            int n = s.size();
            mapp[n].insert(s);
        } 
    }
    
    bool search(string sw) {
        int n = sw.size();
        auto& sett = mapp[n];
        for(int i = 0; i < n; i++) {
            char c = sw[i]-'a';
            for(int j = 0; j < 26; j++) {
                if(j != c) {
                    sw[i] = j + 'a';
                    if(sett.find(sw) != sett.end()) return 1;
                }
            }
            sw[i] = c + 'a';
        }
        
        return 0;
    }
};

// Solution 1
class MagicDictionary {
    unordered_set<string> sett;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto& s: dictionary) {
            sett.insert(s);
        } 
    }
    
    bool search(string sw) {
        int n = sw.size();
        for(int i = 0; i < n; i++) {
            char c = sw[i]-'a';
            for(int j = 0; j < 26; j++) {
                if(j != c) {
                    sw[i] = j + 'a';
                    if(sett.find(sw) != sett.end()) return 1;
                }
            }
            sw[i] = c + 'a';
        }
        
        return 0;
    }
};
