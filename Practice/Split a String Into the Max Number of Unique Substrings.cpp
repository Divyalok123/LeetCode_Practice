/*
https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:

    int helper(string& s, int i, unordered_set<string>& sett) {
        if(i == s.size()) return 0;
        
        int ans = 0;
        string curr;
        for(int j = i; j < s.size(); j++) {
            curr.push_back(s[j]);
            if(sett.count(curr) == 0) {
                sett.insert(curr);
                ans = max(ans, 1 + helper(s, j + 1, sett));
                sett.erase(curr);
            }
        }
        
        return ans;
    }
    
    int maxUniqueSplit(string s) {
        unordered_set<string> sett;
        return helper(s, 0, sett);
    }
};