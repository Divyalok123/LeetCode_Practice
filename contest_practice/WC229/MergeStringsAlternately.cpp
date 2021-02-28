/*
https://leetcode.com/contest/weekly-contest-229/problems/merge-strings-alternately/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        string ans;
        int i = 0, j = 0;
        while(i < n && j < m) {
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }
        
        if(i < n) ans += word1.substr(i, n-i);
        if(j < m) ans += word2.substr(j, m-j);
            
        return ans;
    }
};