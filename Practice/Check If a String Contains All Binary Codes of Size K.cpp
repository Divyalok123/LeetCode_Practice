/*
https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size(), total = 1 << k;
        if(k > n) return 0;
        
        bool check[total];
        memset(check, 0, sizeof(check));
        
        int currval = 0;
        for(int i = 0; i < k; i++) {
            currval <<= 1;
            currval += s[i]-'0';
        }
        
        check[currval] = 1, total--;
        int bitunset = total;
        for(int i = k; i < n; i++) {
            currval <<= 1;
            currval &= bitunset;
            currval += s[i]-'0';
            
            if(check[currval] == 0)
                check[currval] = 1, total--;
        }
        
        return total == 0;
    }
};