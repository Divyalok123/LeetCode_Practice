/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3613/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if(n != m) return 0;
        if(n == 0) return 1;
        
        vector<int> v(26), v2(26);
        for(int i = 0; i < n; i++) 
            v[word1[i]-'a']++, v2[word2[i]-'a']++;
        
        for(int i = 0; i < 26; i++) 
            if((v[i] == 0 && v2[i]) || (v[i] && v2[i] == 0))
                return 0;
                
        sort(v.begin(), v.end());
        sort(v2.begin(), v2.end());
        return v == v2;
    }
};