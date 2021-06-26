/*
https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int fio = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xorr = 0;
        for(int& i: arr2)
            xorr ^= i;
        
        int ans = 0;
        for(int& i: arr1)
            ans ^= (i & xorr);
        
        return ans;
    }
};