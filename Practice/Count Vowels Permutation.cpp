/*
https://leetcode.com/problems/count-vowels-permutation/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        if(n == 1) return 5;
        int MOD = 1000000007;
        
        int a, e, i, o, u;
        a = e = i = o = u = 1;
        
        int na, ne, ni, no, nu;
        while(--n) {
            na = (0ll + e + u + i)%MOD;
            ne = (0ll + a + i)%MOD;
            ni = (0ll + e + o)%MOD;
            no = i;
            nu = (0ll + i + o)%MOD;
            a = na, e = ne, i = ni, o = no, u = nu;
        }
        
        return (0ll + a + e + i + o + u)%MOD;
    }
};