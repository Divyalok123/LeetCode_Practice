/*
https://leetcode.com/contest/weekly-contest-252/problems/count-number-of-special-subsequences/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    #define MOD 1000000007
    #define ll long long
    
    ll power(ll a, ll b) {
        ll ans = 1;
        while(b) {
            if(b&1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        
        return ans;
    }
    
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        
        ll prez = 0, pre1 = 0;
        ll cnt2 = 0;
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] == 2) cnt2++;
            else if(nums[i] == 1) {
                ll val = power(2ll, cnt2) - 1ll;
                ll curr = (val + 2*pre1) % MOD;
                pre1 = curr;
            } else {
                ll val = (pre1 + 2*prez) % MOD;
                prez = val;
            }
        }
        
        return prez;
    }
};
