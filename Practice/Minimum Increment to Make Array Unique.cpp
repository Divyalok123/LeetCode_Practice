/*
https://leetcode.com/problems/minimum-increment-to-make-array-unique/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        if(n == 1) return 0;
        
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(A[i] <= A[i-1]) {
                int val = A[i-1]-A[i] + 1; 
                ans += val;
                A[i] += val;
            }
        }
        
        return ans;
    }
};