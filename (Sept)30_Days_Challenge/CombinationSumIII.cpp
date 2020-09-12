/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3457/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(int k, int n)
    {
        return n >= 1 && n <= (((2*9 + (k-1)*(-1))*k)/2);
    }
    
    void helper(int k, int n, vector<int>& x, vector<vector<int>>& v, int i)
    {
        if(k < 0 || n < 0) return;
        if(k == 0 && n == 0)
        {
            v.push_back(x);
        }
        
        for(int j = i+1; j <= 9-k+1; j++)
            x.push_back(j), helper(k-1, n-j, x, v, j), x.pop_back();
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        
        if(k < 1 || k > 9) return v;
        if(n < 1 || n > 45) return v;
        if(!check(k, n)) return v;
        if(k == 1 && n <= 9) return {{n}};
        
        vector<int> x;
        for(int i = 1; i <= 9-k+1; i++)
            x.push_back(i), helper(k-1, n-i, x, v, i), x.pop_back();
        return v;
    }
};