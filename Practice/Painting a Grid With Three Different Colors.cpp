/*
https://leetcode.com/problems/painting-a-grid-with-three-different-colors/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// improving with bitmask
class Solution {
    #define MOD 1000000007
    #define ll long long
    vector<vector<int>> cache;
    vector<int> states;
    int sz;
public:
    
    int power(int x, int y) {
        int res = 1;
        while(y) {
            if(y & 1) 
                res = (res * 1ll * x) % MOD;
            x = (x * 1ll * x) % MOD;
            y >>= 1;
        }
        
        return res;
    }
    
    void getstates(int i, int m, int mask, int pre) {
        if(i == m) {
            states.push_back(mask);
            return;
        }
        
        mask <<= 2;
        for(int j = 1; j <= 3; j++) {
            if(j != pre)
            {
                mask |= j;
                getstates(i + 1, m, mask, j);
                mask ^= j;
            }
        }
    }
        
    int dfs(int i, int prev, int n, int m) {
        if(i == n) return 1;
        
        int& ans = cache[i][prev];
        if(ans) return ans;
        
        int prevs = i == 0 ? 0 : states[prev];
        for(int j = 0; j < sz; j++) {
            int curr = states[j];
            int k, bit;
            for(k = 0, bit = 3; k < m; k++, bit <<= 2) 
                if((curr & bit) == (prevs & bit)) 
                    break;
            
            if(k != m) continue;
            ans = (ans + 0ll + dfs(i + 1, j, n, m)) % MOD;
        }
        
        return ans;
    }
    
    int colorTheGrid(int m, int n) {
        if(m == 1) return (3ll * power(2, n-1)) % MOD;
        getstates(0, m, 0, -1);
        sz = states.size();
        cache.resize(n+1, vector<int>(sz));
        return dfs(0, 0, n, m);   
    }
};

// dfs with memo - O(n * sz * sz * m)
class Solution {
    #define MOD 1000000007
    vector<vector<int>> cache;
    vector<string> states;
    int sz;
public:
    
    int power(int x, int y) {
        int res = 1;
        while(y) {
            if(y & 1) 
                res = (res * 1ll * x) % MOD;
            x = (x * 1ll * x) % MOD;
            y >>= 1;
        }
        
        return res;
    }
    
    void getstates(int i, int m, string& str) {
        if(i == m) {
            states.push_back(str);
            return;
        }
        
        for(const char c: {'R', 'G', 'B'}) {
            if(str.size() == 0 || str.back() != c)
            {
                str.push_back(c);
                getstates(i + 1, m, str);
                str.pop_back();
            }
        }
    }
        
    int dfs(int i, int prev, int n, int m) {
        if(i == n) return 1;
        
        int& ans = cache[i][prev];
        if(ans) return ans;
        
        string prevs = i == 0 ? string(m, '-') : states[prev];
        int k;
        for(int j = 0; j < sz; j++) {
            string curr = states[j];
            for(k = 0; k < m; k++) if(curr[k] == prevs[k]) break;
            if(k != m) continue;
            ans = (ans + 0ll + dfs(i + 1, j, n, m)) % MOD;
        }
        
        return ans;
    }
    
    int colorTheGrid(int m, int n) {
        if(m == 1) return (3 * 1ll * power(2, n-1)) % MOD;
        string str = "";
        getstates(0, m, str);
        sz = states.size();
        cache.resize(n+1, vector<int>(3 * (1 << m-1)));
        return dfs(0, 0, n, m);   
    }
};