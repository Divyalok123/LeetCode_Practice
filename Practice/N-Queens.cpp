/*
https://leetcode.com/problems/n-queens/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// Solution 2
unordered_set<int> ss1,ss2,ss3;
class Solution {
public:
    void solve(vector<vector<string>>& ans, vector<string>& v, int n, int i) {
        if(i == n) {
            ans.push_back(v);
            return;
        }
        
        int d1, d2;
        for(int j = 0; j < n; j++) {
            d1 = j-i;
            d2 = i+j;
            if(ss1.count(j) || ss2.count(d1) || ss3.count(d2)) continue;
            v[i][j] = 'Q';
            ss1.insert(j);
            ss2.insert(d1);
            ss3.insert(d2);
            solve(ans, v, n, i+1);
            ss1.erase(j);
            ss2.erase(d1);
            ss3.erase(d2);
            v[i][j] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        ss1.clear();
        ss2.clear();
        ss3.clear();
        vector<string> v(n, string(n, '.'));
        solve(ans, v, n, 0);
        return ans;
    }
};

// Solution 1
class Solution {
public:
    
    bool valid(vector<string>& v, int l, int r, int n) {
        int i = l-1, j = r-1;
        while(i >= 0 && j >= 0)
            if(v[i--][j--] == 'Q') return 0;
        
        i = l-1, j = r+1;
        while(i >= 0 && j < n)
            if(v[i--][j++] == 'Q') return 0;
        
        return 1;
    }
    
    void solve(vector<vector<string>>& ans, vector<string>& v, unordered_set<int>& ss, int n, int i) {
        if(i == n) {
            ans.push_back(v);
            return;
        }
        
        for(int j = 0; j < n; j++) {
            if(ss.count(j) || !valid(v, i, j, n)) continue;
            v[i][j] = 'Q';
            ss.insert(j);
            solve(ans, v, ss, n, i+1);
            ss.erase(j);
            v[i][j] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        unordered_set<int> ss;
        vector<string> v(n, string(n, '.'));
        solve(ans, v, ss, n, 0);
        return ans;
    }
};