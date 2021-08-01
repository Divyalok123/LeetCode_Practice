/* https://leetcode.com/problems/word-break/ */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// trie
class Solution {
public:
    
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isWord;

        TrieNode() {
            for(int i = 0; i < 26; i++) children[i] = NULL;
            isWord = false;
        }
    };

    void insert(TrieNode* root, const string& s) {
        int n = s.size();
        TrieNode* temp = root;
        for(int i = 0; i < n; i++) {
            int ind = s[i] - 'a';

            if(temp->children[ind] == NULL)
                temp->children[ind] = new TrieNode();

            temp = temp->children[ind];
        }

        temp->isWord = 1;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        TrieNode* root = new TrieNode();
        for(const string& str: wordDict)
            insert(root, str);

        bool check[301] = {0};
        check[0] = 1;
        for(int i = 1; i <= n; i++) {
            if(!check[i-1]) continue;
            TrieNode* temp = root;
            for(int j = i; j <= n; j++) {
                temp = temp->children[s[j-1]-'a'];
                if(!temp) break;
                if(temp->isWord) 
                    check[j] = 1;
            }
        }

        return check[n];
    }
};

// bfs
class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        int check[300] = {0}, len = s.size();

        queue<int> q;
        q.push(0);

        while(q.size()) {
            int t = q.front();
            q.pop();

            if(!check[t]) {
                check[t] = 1;

                string str = "";
                for(int j = t; j < len; j++) {
                    str.push_back(s[j]);
                    if(us.find(str) != us.end()) {
                        if(j + 1 == len) return true;
                        q.push(j + 1);
                    }
                }
            }
            
        }

        return false;
    }
};

// top-down dp
class Solution {
public:
    int check[300];
    bool dfs(const string& s, unordered_set<string>& us, int i) {
        if(i == s.size()) return true;
        
        if(check[i] != -1) return check[i];
        
        string str = "";
        bool ans = false;
        for(int j = i; j < s.size(); j++) {
            str.push_back(s[j]);
            if(us.find(str) != us.end()) {
                ans |= dfs(s, us, j + 1);
                if(ans == 1)
                    break;
            }
        }
        
        return check[i] = ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        memset(check, -1, sizeof check);
        return dfs(s, us, 0);
    }
};