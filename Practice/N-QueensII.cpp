/*
https://leetcode.com/problems/n-queens-ii/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Solution 3 (Further improvement)
class Solution {
public:
    vector<bool> v1, v2, v3;
    void solve(int& ans, int n, int i) {
        if(i == n) {
            ans++;
            return;
        }

        int d1, d2;
        for(int j = 0; j < n; j++) {
            d1 = i-j + n-1;
            d2 = i+j;
            if(v1[j] || v2[d1] || v3[d2]) continue;
            v1[j] = 1;
            v2[d1] = 1;
            v3[d2] = 1;
            solve(ans, n, i+1);
            v1[j] = 0;
            v2[d1] = 0;
            v3[d2] = 0;
        }
    }
    
    int totalNQueens(int n) {
        v1.assign(10, 0);
        v2.assign(20, 0);
        v3.assign(20, 0);
        int ans = 0;
        solve(ans, n, 0);
        return ans;
    }
};


// Solution 2
unordered_set<int> ss1, ss2, ss3;
class Solution {
public:
    void solve(int& ans, int n, int i) {
        if(i == n) {
            ans++;
            return;
        }
    
        int d1, d2;
        for(int j = 0; j < n; j++) {
            d1 = j-i;
            d2 = i+j;
            if(ss1.count(j) || ss2.count(d1) || ss3.count(d2)) continue;
            ss1.insert(j);
            ss2.insert(d1);
            ss3.insert(d2);
            solve(ans, n, i+1);
            ss1.erase(j);
            ss2.erase(d1);
            ss3.erase(d2);
        }
    }
    
    int totalNQueens(int n) {
        int ans = 0;
        ss1.clear();
        ss2.clear();
        ss3.clear();
        solve(ans, n, 0);
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

    void solve(int& ans, vector<string>& v, unordered_set<int>& ss, int n, int i) {
        if(i == n) {
            ans++;
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
    
    int totalNQueens(int n) {
        int ans = 0;
        unordered_set<int> ss;
        vector<string> v(n, string(n, '-'));
        solve(ans, v, ss, n, 0);
        return ans;
    }
};