/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3471/
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*---- Method 2 ----*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = t.back();
        for(int i = 0; i < s.size(); i++)
            ans ^= s[i], ans ^= t[i];
        
        return ans;
    }
};

/*---- Method 1 ----*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26);
        
        for(int i = 0; i < t.size(); i++)
        {
            if(i != t.size()-1) v[s[i]-'a']--;
            v[t[i]-'a']++;
        }
        
        int i;
        for(i = 0; i < 26; i++)
            if(v[i] == 1)
                break;
        return 'a' + i;
    }
};