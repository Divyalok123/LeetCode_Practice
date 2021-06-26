/*
https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<int>& arrmask, int i, int curr, int& ans) {
        if(i == arrmask.size())
        {
            int setbits = __builtin_popcount(curr);
            if(setbits > ans)
                ans = setbits;
            
            return;
        }

        helper(arrmask, i+1, curr, ans);
        if((curr & arrmask[i]) == 0)
            helper(arrmask, i+1, curr | arrmask[i], ans);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> arrmask;
        for(int i = 0; i < n; i++) {
            int MASK = 0, check = 1;
            for(char& c: arr[i]) {
                int val = 1 << (c-'a');
                if(MASK & val) { 
                    check = 0;
                    break;
                }
                MASK |= val;
            }
            
            if(check)
                arrmask.push_back(MASK);
        }
        
        int ans = 0;
        helper(arrmask, 0, 0, ans);
        return ans;
    }
};