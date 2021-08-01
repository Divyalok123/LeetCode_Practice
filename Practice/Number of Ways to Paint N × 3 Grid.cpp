/*
https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// much smarter : using the recursion equation
class Solution {
public:
    #define MOD 1000000007
    #define ll long long
    
    int numOfWays(int n) {
        ll currfor2 = 6;
        ll currfor3 = 6;
        
        for(int i = 2; i <= n; i++) {
            ll temp = currfor2;
            currfor2 = (2 * currfor3 + 3 * currfor2) % MOD;
            currfor3 = (2 * currfor3 + 2 * temp) % MOD;
        }
        
        return (currfor2 + currfor3) % MOD;
    }
};

// dp + memo - O(n * 12 * 12 * 3)
class Solution {
public:
    #define MOD 1000000007
    int cache[5001][12];
    
    string states[12] = {"RGB", "RGR", "RBG", "RBR", "GBR", "GBG", "GRB", "GRG", "BGB", "BGR", "BRG", "BRB"};
    
    int dfs(int i, int n, int prest) {
        if(i == n) return 1;
        
        int& ans = cache[i][prest];
        if(ans) return ans;
        
        int k;
        string prev = (i == 0) ? "---" : states[prest];
        for(int j = 0; j < 12; j++) {
            string st = states[j];
            k = 0;
            for(k = 0; k < 3; k++) if(st[k] == prev[k]) break;
            
            if(k != 3) continue;
            
            ans = (ans + 0ll +  dfs(i + 1, n, j)) % MOD;
        }
        
        return ans;
    }
    
    int numOfWays(int n) {
        if(n == 1) return 12;
        memset(cache, sizeof cache, 0);
        return dfs(0, n, 0);
    }
};