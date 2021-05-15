/*
https://leetcode.com/problems/fancy-sequence/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

//

// Simple maths
static int fastt = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Fancy {
    vector<int> vec;
    long long incre, mult;
    int MOD;
public:
    
    int power(long long val, int p) {
        int ans = 1;
        while(p) {
            if(p&1)
                ans = (ans*1ll*val)%MOD;
            val = (val*val)%MOD;
            p >>= 1;
        }
        return ans;
    }
    
    int MOD_INVERSE(long long val) {
        return power(val, MOD-2);
    }
    
    Fancy() {
        incre = 0;
        mult = 1;
        MOD = 1000000007;
    }
    
    void append(int val) {
        val = (val-incre+MOD)%MOD;
        val = (val*1ll*MOD_INVERSE(mult))%MOD;
        vec.push_back(val);
    }
    
    void addAll(int inc) {
        incre = (incre + inc)%MOD;
    }
    
    void multAll(int m) {
        incre = (incre*m)%MOD;
        mult = (mult*m)%MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= vec.size())
            return -1;
        return ((vec[idx]*mult)%MOD + incre)%MOD;
    }
};
