/*
https://leetcode.com/problems/maximum-of-absolute-value-expression/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int ans = INT_MIN, n = arr1.size();
        vector<int> p = {-1, 1};
        for(int& i: p) {
            for(int& j: p) {
                int ll = arr1[0]*i + arr2[0]*j;
                for(int k = 1; k < n; k++) {
                    int curr = arr1[k]*i + arr2[k]*j + k;
                    ans = max(ans, curr-ll);
                    ll = min(ll, curr);
                }
            }
        }
        return ans;
    }
};