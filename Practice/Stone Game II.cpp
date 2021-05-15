/*
https://leetcode.com/problems/stone-game-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

// bottom-up dp (not full proof)
class Solution {
public:
    
    vector<vector<int>> cache;
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        if(n == 1)
            return piles[0];
        
        vector<int> sumfrom(n);
        sumfrom[n-1] = piles[n-1];
        for(int i = n-2; i >= 0; i--)
            sumfrom[i] += sumfrom[i+1] + piles[i];
        
        cache.resize(n+1,vector<int>(n+1));
        for(int i = n-1; i >= 0; i--) {
            for(int m = 1; m <= n-1; m++) {
                for(int x = 1; x <= 2*m && i + x <= n; x++) {
                    cache[i][m] = max(cache[i][m], sumfrom[i]-cache[i+x][max(m, x)]);
                }
            }
        }
        
        return cache[0][1];
    }
};

// top-down dp
class Solution {
public:
    vector<vector<int>> cache;
    int helper(vector<int>& piles, int i, int m, vector<int>& sumfrom) {
        if(i >= piles.size())
            return 0;
        
        int& ans = cache[i][m];
        if(ans != -1)
            return ans; 
        
        int lim = min((int)piles.size(), i+2*m);
        int val = 10000000;
        for(int k = i; k < lim; k++) {
            int newval = helper(piles, k+1, max(m, k-i+1), sumfrom);
            if(newval < val)
                val = newval;
        }
        
        return ans = sumfrom[i]-val;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        vector<int> sumfrom(n);
        sumfrom[n-1] = piles[n-1];
        for(int i = n-2; i >= 0; i--)
            sumfrom[i] += sumfrom[i+1] + piles[i];
        
        cache.resize(n,vector<int>(64, -1));
        return helper(piles, 0, 1, sumfrom);
    }
};