/*
https://leetcode.com/problems/longest-happy-prefix/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

// using lcp array
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        int lcp[n];
        lcp[0] = 0;
        
        int i = 1, j = 0;
        while(i < n) {
            if(s[i] == s[j]) {
                j++;
                lcp[i] = j;
                i++;
            } else {
                if(j == 0)
                    lcp[i++] = 0;
                else
                    j = lcp[j-1];
            }
        }
        
        return s.substr(0, lcp[n-1]);
    }
};

// using hashing
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    string longestPrefix(string s) {
        long long p = 52817;
        int MOD = 1000000007, n = s.size(), l = 0;
    
        long long hash1 = 0, hash2 = 0, poww = 1;
        for(int i = 0, j = n-1; i < n-1; i++, j--) {
            hash1 = (hash1*p + s[i]-'a')%MOD;
            hash2 = ((s[j]-'a')*poww + hash2)%MOD;
            poww = (poww*p)%MOD;
            if(hash1 == hash2)
                l = i+1;
        }        
        
        string ans = s.substr(0, l);
        return ans;
    }
};