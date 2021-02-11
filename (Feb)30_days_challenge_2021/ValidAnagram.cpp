/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3636/
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return 0;
        int n = s.size();
        vector<int> v(26);
        for(int i = 0; i < n; i++)
            v[s[i]-'a']++, v[t[i]-'a']--;
        
        for(int i = 0; i < 26; i++)
            if(v[i]) return 0;
        return 1;
    }
};