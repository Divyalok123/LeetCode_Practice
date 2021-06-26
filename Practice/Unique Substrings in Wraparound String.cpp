/*
https://leetcode.com/problems/unique-substrings-in-wraparound-string/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int prev(int i) {
        return i ? i-1 : 25;
    }
    
    int findSubstringInWraproundString(string p) {
        int counts[26] = {0};
        int n = p.size();
        
        int count = 1;
        counts[p[0]-'a'] = 1;
        
        for(int i = 1; i < n; i++) {
            int ind = p[i]-'a';
            
            if(i && p[i-1]-'a' == prev(ind))
                count++;
            else
                count = 1;
            
            counts[ind] = max(counts[ind], count);
        }
        
        int ans = 0;
        for(int& i: counts)
            ans += i;
        
        return ans;
    }
};