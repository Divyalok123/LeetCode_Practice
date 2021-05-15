/*
https://leetcode.com/contest/weekly-contest-238/problems/longest-substring-of-all-vowels-in-order/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        
        unordered_map<char,int> um;
        um['a'] = 0;
        um['e'] = 1;
        um['i'] = 2;
        um['o'] = 3;
        um['u'] = 4;
        
        vector<array<int, 2>> concise;
        int i = 0;
        while(i < n) {
            char c = word[i];
            int count = 1;
            while(i < n-1 && word[i+1] == c)
                i++, count++;
            
            concise.push_back({um[c], count});
            i++;
        }
        
        i = 0, n = concise.size();
        int ans = 0;
        
        while(i <= n-5) {
            if(concise[i][0] == 0) {
                if(concise[i+1][0] == 1 && concise[i+2][0] == 2 && concise[i+3][0] == 3 && concise[i+4][0] == 4)
                    ans = max(ans, concise[i][1] + concise[i+1][1] + concise[i+2][1] + concise[i+3][1] + concise[i+4][1]);
            }
            
            i++;
        }
        
        return ans;
    }
};