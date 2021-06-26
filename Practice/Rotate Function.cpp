/*
https://leetcode.com/problems/rotate-function/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//better implementation
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        long long pre = 0, curr = 0, fans;
        for(int i = 0; i < n; i++) {
            curr += nums[i] * 1ll * i;
            pre += nums[i];
        }
        
        fans = curr;
        int ind = n-1;
        for(int i = 1; i < n; i++) {
            curr -= nums[ind] * 1ll * (n);
            curr += pre;
            if(curr > fans)
                fans = curr;

            ind--;
        }
        
        return fans;
    }
};

// solution 1
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        long long pre = 0;
        for(int i = 0; i < n-1; i++)
            pre += nums[i];
        
        long long curr = 0, fans;
        for(int i = 0; i < n; i++)
            curr += nums[i] * 1ll * i;
        
        fans = curr;
        int ind = n-1;
        for(int i = 1; i < n; i++) {
            curr -= nums[ind] * 1ll * (n-1);
            curr += pre;
            
            if(curr > fans)
                fans = curr;
            
            pre += nums[ind];
            ind--;
            if(ind == -1) ind = n-1;
            pre -= nums[ind];
        }
        
        return fans;
    }
};