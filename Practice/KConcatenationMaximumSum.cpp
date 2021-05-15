/*
https://leetcode.com/problems/k-concatenation-maximum-sum/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == 0) return 0;
            
        int prefixmax = 0, suffixmax = 0, total = 0, subarraymax = 0;
        
        int j = 0, t = 0;
        while(j < n) {
            if(t < 0) t = arr[j];
            else t += arr[j];
            
            if(t > subarraymax)
                subarraymax = t;
            j++;
        }

        if(k == 1) return subarraymax;
        
        t = 0;
        for(int i = 0; i < n; i++) {
            total += arr[i];
            t += arr[n-i-1];
            if(total > prefixmax)
                prefixmax = total;
            if(t > suffixmax)
                suffixmax = t;
        }
        
        if(total <= 0) return max(suffixmax + 0ll + prefixmax, 1ll*subarraymax)%MOD;
        return max(suffixmax + 0ll + prefixmax + total*1ll*(k-2), 1ll*subarraymax)%MOD;
    }
};