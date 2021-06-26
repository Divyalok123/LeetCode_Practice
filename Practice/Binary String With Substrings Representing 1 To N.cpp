/*
https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// simple O(slogn) solution
class Solution {
public:
    bool queryString(string s, int n) {
        if(n > 2*s.size()) return false;

        unordered_set<int> sett;
        int sz = s.size(), maxx = log2(n);
        for(int i = 0; i < sz; i++) {
            if(s[i] == '0') continue;
            int val = 0;
            int lim = min(sz-1, i + maxx);
            for(int j = i; j <= lim; j++) {
                val <<= 1;
                val += s[j]-'0';
                sett.insert(val);
            }
        }
        
        sz = sett.size();
        int v[sz], ind = 0;
        
        for(const int& i: sett)
            v[ind++] = i;

        sort(v, v + sz);
        
        int dist = lower_bound(v, v + sz, n) - v;
        if(dist == sz || v[dist] != n) return false;
        if(dist + 1 != n) return false;
        return true;
    }
};