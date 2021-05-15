/*
https://leetcode.com/problems/subarray-sums-divisible-by-k/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int count = 0, n = A.size();
        vector<int> c(K+1);

        for(int i = 1; i < n; i++) 
            A[i] += A[i-1];
        
        for(int i = 0; i < n; i++) {
            A[i] %= K;
            if(A[i] < 0) A[i] += K;
            c[A[i]]++;
        }        
        
        count += c[0]*(c[0]+1)/2;
        for(int i = 1; i <= K; i++) {
            if(c[i]) {
                ll& a = c[i];
                count += a*(a-1)/2;
                a = 0;
            }
        }
        
        return count;
    }
};