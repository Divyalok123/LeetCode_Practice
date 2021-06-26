/*
https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// simple counting
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        if(n == 1) return 0;
        
        int count1 = 0, count2 = 0;
        int left[26] = {0}, right[26] = {0};
        
        for(int i = 1; i < n; i++) {
            if(right[s[i]-'a'] == 0)
                count2++;
            right[s[i]-'a']++;
        }
        
        left[s[0]-'a']++;
        count1 = 1;
        
        if(count1 == count2)
            return s[0] == s[1] ? n-1 : 1;

        int ans = 0;
        for(int i = 1; i < n-1; i++) {
            left[s[i]-'a']++;
            right[s[i]-'a']--;
            
            if(left[s[i]-'a'] == 1) count1++;
            if(right[s[i]-'a'] == 0) count2--;
            
            if(count1 == count2)
                ans++;
        }
        
        return ans;
    }
};