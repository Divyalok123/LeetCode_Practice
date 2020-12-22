/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3573/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void countsort(vector<int>& A) {
        int maxe = *max_element(A.begin(), A.end());
        
        vector<int> con(maxe+1);
        for(int& a: A)
            con[a]++;
        
        int k = 0;
        for(int i = 0; i < maxe+1; i++) {
            if(con[i]) {
                while(con[i]--) 
                    A[k++] = i;
            }
        }
    }
    
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        if(n <= 1) return 0;
        
        
        //counting sort
        countsort(A);
        
//         cout << "Arr: ";
//         for(int& a: A)
//             cout << a << " ";
//         cout << endl;
        
        
        int minv = A.front(), maxv = A.back();
        int res = maxv-minv;
        for(int i = 0; i < n-1; i++) {
            maxv = max(A.back()-K, A[i]+K);
            minv = min(A.front()+K, A[i+1]-K);
            res = min(res, maxv-minv);
        }
        
        return res;
    } 
};