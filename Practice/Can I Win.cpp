/*
https://leetcode.com/problems/can-i-win/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> cache;
    bool solve(int dt, int mci, int curr, vector<bool>& check) {
        if(dt <= 0) return true;
        
        if(cache[curr] != -1)
            return cache[curr];
        
        for(int i = 1; i <= mci; i++) {
            if(!check[i]) {
                if(dt <= i)
                    return cache[curr] = 1;
                
                check[i] = 1;
                bool opp = solve(dt-i, mci, curr | (1 << i), check);
                check[i] = 0;
                
                if(!opp)
                    return cache[curr] = 1;
            }
        }
        
        return cache[curr] = 0;
    }
    
    bool canIWin(int mci, int dt) {
        if(dt < mci) return true;
        if(dt > mci*(mci+1)/2) return false;
        
        cache.resize(1<<mci + 1, -1);
        vector<bool> check(mci+1);
        return solve(dt, mci, 0, check);        
    }
};