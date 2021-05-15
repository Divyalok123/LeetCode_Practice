/*
https://leetcode.com/problems/number-of-matching-subsequences/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <deque>
using namespace std;

// parallel searching - O(s.size() + (word.size() in words))
class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {
        deque<const char*> ind[26];
        int n = s.size(), m = words.size();
        for(auto& word: words)
            ind[word[0]-'a'].push_back(word.c_str());
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int ch = s[i]-'a';
            int sz = ind[ch].size();
            for(int j = 0; j < sz; j++) {
                auto front = ind[ch].front();
                ind[ch].pop_front();
                front++;
                if(*front == '\0')
                    ans++;
                else 
                    ind[front[0]-'a'].push_back(front);
            }
        }
        
        return ans;
    }

};

// sorted index solution - O(s.size() + (word.size()*log(s.size()) in words))
class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> ind[26];
        int n = s.size(), m = words.size();
        
        for(int i = 0; i < n; i++)
            ind[s[i]-'a'].push_back(i);
        
        unordered_map<string, bool> um;
        
        int ans = 0;
        for(auto& word: words) {
            int lastind = -1, check = 1;
            if(um[word])
                ans++;
            else {
                for(auto& ch: word) {
                    auto& ref = ind[ch-'a'];
                    auto ind = upper_bound(ref.begin(), ref.end(), lastind);
                    if(ind == ref.end()) {
                        check = 0;
                        break;
                    }
                    lastind = *ind;
                }

                if(check) {
                    um[word] = 1;
                    ans+=1;
                }
            }
        }
        
        return ans;
    }

};

// naive subsequence check solution (O(s.size() * (word.size() in words)))
class Solution {
public:
    bool isin(const string& s, const string& w) {
        int m = s.size(), n = w.size();
        
        if(m < n) return false;
        else if(m == n) return s == w;
        
        int i = 0, j = 0;
        while(j < m && i < n) {
            if(w[i] == s[j])
                i++;
            j++;
        }
        
        return i == n;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> um;
        for(auto& i: words)
            um[i]++;
        
        int ans = 0;
        for(const auto& [i, j]: um)
            if(isin(s, i))
                ans+=j;
        
        return ans;
    }

};