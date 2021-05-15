/*
https://leetcode.com/problems/prefix-and-suffix-search/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

// using single trie
class WordFilter {
    class TrieNode {
    public:
        array<TrieNode*, 27> ch;
        int mainind;
        
        TrieNode() {
            mainind = -1;
            for(int i = 0; i < 27; i++)
                ch[i] = nullptr;
        }
    };  
    
    TrieNode* trie;
    
    void insertword(TrieNode* curr, string& s, int ind) {
        curr->mainind = ind;
        for(int i = 0; i < s.size(); i++) {
            int x = s[i]-'a';
            if(!curr->ch[x])
                curr->ch[x] = new TrieNode();
            curr = curr->ch[x];
            curr->mainind = ind;
        }
    }
    
    int searchword(TrieNode* curr, string& s) {
        for(char c: s) {
            curr = curr->ch[c-'a'];
            if(!curr)
                return -1;
        }
        
        return curr->mainind; 
    }
    
public:
    WordFilter(vector<string>& words) {
        trie = new TrieNode();
        
        for(int i = 0; i < words.size(); i++) {
            const string& word = words[i];
            for(int j = 0; j < word.size(); j++) {
                string toinsert = word.substr(j) + "{" + word;
                insertword(trie, toinsert, i);
            }
        }
        
    }
    
    int f(string prefix, string suffix) {
        string tosearch = suffix + "{" + prefix;
        return searchword(trie, tosearch);
    }
};

// using two tries - FASTEST - initialization: O(words*size) - f: O(words.size())
class WordFilter {
    class TrieNode {
    public:
        array<TrieNode*, 26> ch;
        vector<int> inds;
        
        TrieNode() {
            for(int i = 0; i < 26; i++)
                ch[i] = nullptr;
        }
    };  
    
    TrieNode* suffixTrie, *prefixTrie;
    
    void insertword(TrieNode* curr, string& s, int ind) {
        curr->inds.push_back(ind);
        for(int i = 0; i < s.size(); i++) {
            int x = s[i]-'a';
            if(!curr->ch[x])
                curr->ch[x] = new TrieNode();
            curr = curr->ch[x];
            curr->inds.push_back(ind);
        }
    }
    
public:
    WordFilter(vector<string>& words) {
        suffixTrie = new TrieNode();
        prefixTrie = new TrieNode();
        
        for(int i = 0; i < words.size(); i++) {
            insertword(prefixTrie, words[i], i);
            reverse(words[i].begin(), words[i].end());
            insertword(suffixTrie, words[i], i);
        }
        
    }
    
    int f(string prefix, string suffix) {
        TrieNode* temppre = prefixTrie;
        TrieNode* tempsuf = suffixTrie;
        
        for(char c: prefix) {
            temppre = temppre->ch[c-'a'];
            if(!temppre)
                return -1;
        }
        
        reverse(suffix.begin(), suffix.end());
        for(char c: suffix) {
            tempsuf = tempsuf->ch[c-'a'];
            if(!tempsuf)
                return -1;
        }
        
        auto& arrpre = temppre->inds;
        auto& arrsuf = tempsuf->inds;
        
        int n = arrpre.size(), m = arrsuf.size(), i = n-1, j = m-1;
        while(i >= 0 && j >= 0) {
            if(arrpre[i] == arrsuf[j])
                return arrpre[i];
            else if(arrpre[i] > arrsuf[j])
                i--;
            else
                j--;
        }
        
        return -1;
    }
};

// naive solution (getting all prefixes and suffixes)
class WordFilter {
    unordered_map<string, set<int>> ump;
    unordered_map<string, unordered_set<int>> ums;
    
public:
    WordFilter(vector<string>& words) {
        int ind = 0;
        for(auto& word: words) {
            int n = word.size();
            //pre
            string s = "";
            for(int i = 0; i < n; i++) {
                s.push_back(word[i]);
                ump[s].insert(ind);
            }
            
            //suf
            s = word;
            for(int i = 0; i < n; i++) {
                ums[s].insert(ind);
                s = s.substr(1);
            }
            ind++;
        }
    }
    
    int f(string prefix, string suffix) {
        auto& ref = ump[prefix];
        auto& ref2 = ums[suffix];
        
        auto itr = ref.end();
        int sz = ref.size();
        
        while(sz--) {
            itr = prev(itr);
            int ind = *itr;
            if(ref2.find(ind) != ref2.end())
                return ind;
        }
        
        return -1;
    }
};
