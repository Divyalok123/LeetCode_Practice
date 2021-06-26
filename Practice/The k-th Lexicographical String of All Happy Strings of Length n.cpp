/*
https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int count;
    void dfs(string& s, vector<string>& vec, int n) {
        if(s.size() == n) {
            count--;
            vec.emplace_back(s);
            return;
        }
        
        if(!count) return;
        
        for(char c: {'a', 'b', 'c'})
            if(s.size() == 0 || s.back() != c) {
                s.push_back(c);
                dfs(s, vec, n);
                s.pop_back();
            }
        
    }
    
    string getHappyString(int n, int k) {
        vector<string> v;
        string s;
        count = k;
        dfs(s, v, n);
        if(v.size() < k) return "";
        return v[k-1];        
    }
};