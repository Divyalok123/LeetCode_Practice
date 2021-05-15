/*
https://leetcode.com/problems/get-equal-substrings-within-budget/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), i = 0, j = 0;
        int cost = 0, ans = 0;
        while(j < n) {
            if(s[j] != t[j])
                cost += abs(s[j]-t[j]);
            
            while(cost > maxCost)
            {
                if(s[i] != t[i])
                    cost -= abs(s[i]-t[i]);
                i++;
            }
            
            ans = max(ans, j-i+1);
            j++;
        }
        
        return ans;
    }
};