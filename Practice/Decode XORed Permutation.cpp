/*
https://leetcode.com/problems/decode-xored-permutation/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size()+1;
        vector<int> decoded(n);
        
        int last = 0;
        for(int i = 1; i <= n; i++)
            last ^= i;
        
        for(int i = 0; i < n-1; i += 2)
            last ^= encoded[i];
        
        decoded[n-1] = last;
        for(int i = n-2; i >= 0; i--)
            decoded[i] = encoded[i] ^ decoded[i+1];
        
        return decoded;
    }
};