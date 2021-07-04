/*
https://leetcode.com/contest/weekly-contest-245/problems/redistribute-characters-to-make-all-strings-equal/
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> count(26);
        for(auto& w: words) {
            for(auto& c: w) {
                count[c-'a']++;
            }
        }
        
        int n = words.size();
        for(int& i: count) {
            if((i % n) != 0)
                return false;
        }
        
        return true;
    }
};