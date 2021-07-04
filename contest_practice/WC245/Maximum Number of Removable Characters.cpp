/*
https://leetcode.com/contest/weekly-contest-245/problems/maximum-number-of-removable-characters/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int rn = removable.size();
        if(rn == 0) return 0;
        if(s.size() == p.size()) return 0;
        
        int l = 0, r = rn-1, sn = s.size(), pn = p.size();
        
        while(l <= r) {
            int m = l + (r-l)/2;
            bool check[sn];
            memset(check, 0, sizeof(check));
            
            for(int i = 0; i <= m; i++)
                check[removable[i]] = 1;
            
            int i = 0, j = 0;
            while(i < sn && j < pn) {
                if(!check[i] && s[i] == p[j])
                    j++;
                i++;
            }
            
            if(j == pn)
                l = m+1;
            else
                r = m-1;
        }
        
        return l;
    }
};