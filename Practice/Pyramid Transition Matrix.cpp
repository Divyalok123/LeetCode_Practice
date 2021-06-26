/*
https://leetcode.com/problems/pyramid-transition-matrix/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// little better
class Solution {
public:
    unordered_map<string, vector<char>> um;
    bool dfs(string bottom, string newbottom, int i) {
        int sz = bottom.size();
        if(sz == 1)
            return 1;
    
        if(i == sz-1)
            return dfs(newbottom, "", 0);
        
        string curr = bottom.substr(i, 2);
        for(char c: um[curr])
            if(dfs(bottom, newbottom + c, i+1))
                return 1;
        
        return 0;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = allowed.size();
        if(n == 0) return 0;
        
        for(string& i: allowed)
            um[i.substr(0, 2)].push_back(i[2]);
        
        return dfs(bottom, "", 0);
    }
};

// simple dfs
class Solution {
public:
    unordered_map<string, int> um;
    bool dfs(string bottom, string newbottom, int i) {
        int sz = bottom.size();
        if(sz == 1)
            return 1;
    
        if(newbottom.size() == sz-1)
            return dfs(newbottom, "", 0);
        
        string curr = bottom.substr(i, 2);
        for(int bit = 1 << 6, ind = 6; bit; bit >>= 1, ind--) {
            if(um[curr] & bit) {
                string nn = newbottom;
                nn.push_back(ind + 'A');
                if(dfs(bottom, nn, i+1))
                    return 1;
            }
        }
        return 0;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = allowed.size();
        if(n == 0) return 0;
        
        for(string& i: allowed)
            um[i.substr(0, 2)] |= (1 << (i[2]-'A'));
        
        return dfs(bottom, "", 0);
    }
};