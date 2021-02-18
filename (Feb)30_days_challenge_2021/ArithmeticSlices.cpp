/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3644/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        
        int ans = 0, sz = 0, i = 2;
        while(i < n) {
            if(A[i]-A[i-1] == A[i-1]-A[i-2])
                sz++;
            else {
                ans += (sz)*1ll*(sz+1)/2l;
                sz = 0;
            }
            i++;
        }
        ans += sz*1ll*(sz+1)/2l;
        return ans;
    }
};

