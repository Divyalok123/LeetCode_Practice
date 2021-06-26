/*
https://leetcode.com/problems/longest-string-chain/submissions/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// bottom-up
class Solution {
public:
    bool areFine(const string& a, const string& b) {
        int n = a.size(), m = b.size(), i = 0, j = 0;
        while(i < n && j < m) {
            if(a[i] == b[j])
                i++, j++;
            else {
                i++;
                if(i-j > 1)
                    return 0;
            }
        }
        
        return 1;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size(), end = 1;
        vector<pair<string, int>> store[17];
        
        for(auto& i: words) {
            store[i.size()].push_back({i, 1});
            end = max(end, (int)i.size());
        }
        
        int ans = 1;
        for(int i = 2; i <= end; i++)
            for(auto& [a, aval]: store[i])
                for(const auto& [b, bval]: store[i-1])
                    if(areFine(a, b)) {
                        aval = max(aval, bval + 1);
                        ans = max(ans, aval);
                    }
        
        return ans;
    }
};

// Improved top-down 
class Solution {
public:
    vector<unordered_set<string>> inds;
    unordered_map<string, int> cache;
    
    int solve(const string& curr) {
        int n = curr.size();
        if(n == 1)
            return 0;
        
        int& ans = cache[curr];
        if(ans)
            return ans;
        
        string ss = "";
        for(int i = 0; i < n; i++) {
            string s = ss + curr.substr(i+1);
            if(inds[n-1].find(s) != inds[n-1].end())
                ans = max(ans, 1 + solve(s));
            ss.push_back(curr[i]);
        }
        
        return ans;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size(), start = 0;
        
        inds.resize(17);
        for(auto& i: words)
            inds[i.size()].insert(i);
        
        int ans = 1;
        for(int i = 16; i >= 1 && ans <= i; i--)
            for(const auto& j: inds[i])
                ans = max(ans, solve(j) + 1);
        
        return ans;
    }
};

// naive top-down dp
class Solution {
public:
    vector<unordered_set<string>> inds;
    unordered_map<string, int> cache;
    
    int solve(string& curr) {
        if(curr.size() == 1)
            return 0;
    
        if(cache[curr])
            return cache[curr];
        
        int n = curr.size();
        string ss = "";
        int ans = 0;
        for(int i = 0; i < n; i++) {
            string s = ss + curr.substr(i+1);
            if(inds[n-1].find(s) != inds[n-1].end())
                ans = max(ans, 1 + solve(s));
            ss.push_back(curr[i]);
        }
        
        return cache[curr] = ans;
    }
    
    int longestStrChain(vector<string>& words) {
        int maxx = 0, n = words.size();
        for(auto& i: words)
            maxx = max(maxx, (int)i.size());
        
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() > b.size();
        });
        
        inds.resize(maxx+1);
        for(auto& i: words)
            inds[i.size()].insert(i);
        
        int ans = 1;
        for(int i = 0; i < n && ans < n-i; i++) {
            ans = max(ans, solve(words[i]) + 1);
        }
        
        return ans;
    }
};