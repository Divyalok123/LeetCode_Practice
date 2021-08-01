/*
https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size();
        int ans = 0, mask = 0;
        unordered_map<char, int> um;
        um['a'] = 1;
        um['e'] = 2;
        um['i'] = 3;
        um['o'] = 4;
        um['u'] = 5;
        
        int found[100] = {0};
        for(int i = 0; i < n; i++) {
            if(um[s[i]])
                mask ^= (1 << um[s[i]]);
            
            if(mask == 0) 
                ans = i + 1;
            else {            
                if(found[mask])
                    ans = max(ans, i-found[mask] + 1);
                else    
                    found[mask] = i+1;
            }
        }
        
        return ans;
    }
};