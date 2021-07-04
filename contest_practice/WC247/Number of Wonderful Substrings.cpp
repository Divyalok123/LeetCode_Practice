/*
https://leetcode.com/contest/weekly-contest-247/problems/number-of-wonderful-substrings/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int MASK = 0;
        int n = word.size();
        long long um[1040] = {0};
        um[0] = 1;
        
        int store[10];
        for(int i = 0; i < 10; i++)
            store[i] = (1 << i);
        
        long long ans = 0;
        for(char c: word) {
            MASK ^= store[c-'a'];
            ans += um[MASK];
            
            for(int i = 0; i < 10; i++)
                ans += um[MASK ^ store[i]];
            
            um[MASK]++;
        }
        
        return ans;
    }
};